#include <stdint.h>
#include "stm32l476xx.h"
#include "core_cm4.h"
#include <string.h>
//#include "onewire.h"
#define LCD_RSPin 1
#define LCD_RWPin 5
#define LCD_ENPin 6
int timeout = 0;
typedef struct {
	GPIO_TypeDef* GPIOx;           /*!< GPIOx port to be used for I/O functions */
	uint32_t GPIO_Pin;             /*!< GPIO Pin to be used for I/O functions */
} OneWire_t;
void systick_init(){
	SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
	SysTick->CTRL |= SysTick_CTRL_TICKINT_Msk;
	SysTick->CTRL |= SysTick_CTRL_CLKSOURCE_Msk;
	SysTick->LOAD = (uint32_t) 3000000;
}
void system_clock_config(){
		// 10M Hz
		RCC->CFGR &= 0xfffff000;
		RCC->CR &= 0xFEFFFFFF;
		while((RCC->CR & RCC_CR_PLLRDY) > 0);
		RCC->PLLCFGR &= 0xf9ff808f;
		RCC->PLLCFGR |= 2; //set clock source
		RCC->PLLCFGR |= RCC_PLLCFGR_PLLN_0;
		RCC->PLLCFGR |= RCC_PLLCFGR_PLLN_1;
		RCC->PLLCFGR |= RCC_PLLCFGR_PLLN_2;
		RCC->PLLCFGR |= RCC_PLLCFGR_PLLN_3;
		RCC->PLLCFGR |= RCC_PLLCFGR_PLLM_1;
		RCC->PLLCFGR |= RCC_PLLCFGR_PLLR_0;
		RCC->PLLCFGR |= RCC_PLLCFGR_PLLR_1;
		RCC->CR |= RCC_CR_PLLON;
		RCC->CR |= RCC_CR_HSION;
		RCC->PLLCFGR |= RCC_PLLCFGR_PLLREN;
		RCC->CFGR |= 15;
}
void GPIO_init(){
	RCC->AHB2ENR = RCC->AHB2ENR | 0x7;

	GPIOC->MODER = (GPIOC->MODER & 0xf3ffffff);

	GPIOB->MODER =  (GPIOB->MODER & 0xffff0000) |0x5555 ;
	GPIOB->PUPDR = (GPIOB->PUPDR & 0xffff0000) | 0xAAAA;
	GPIOB->OSPEEDR = (GPIOB->OSPEEDR & 0xffff0000) | 0x5555;
	GPIOB->OTYPER = 0;

	GPIOA->MODER =  (GPIOA->MODER & 0xffff0000) |0x5555 ;
	GPIOA->PUPDR = (GPIOA->PUPDR & 0xffff0000) | 0xAAAA;
	GPIOA->OSPEEDR = (GPIOA->OSPEEDR & 0xffff0000) | 0x5555;
	GPIOA->OTYPER = 0;
	//GPIOB->ODR = 0xff;
}

void wait(int microsec){
    SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
	SysTick->LOAD = (uint32_t) 3000000;
    timeout = 0;
    while(!timeout); 
}
int write_to_LCD(int input,int is_cmd){
    if(is_cmd==1)
    		GPIOA->BRR |= 1 <<(LCD_RSPin );
    	else
    		GPIOA->BSRR |= 1 << (LCD_RSPin);
    	GPIOA->BRR |= 1 <<(LCD_RWPin);
    GPIOB->BRR |= 0xff;
    	GPIOB->BSRR |= input;
    	GPIOA->BSRR |= 1 << (LCD_ENPin);
    	wait();
    	GPIOA->BRR |= 1<< (LCD_ENPin);
    	wait();
}
int offset = 16;
int addr=0;
int Array[16]={0x34,0x37,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20};
int prefix = 0x80;
int t_prefix = 0xC0;
int counter = 0;
int mode = 1;
char str[] = "This is a test";
int s_len;
int count;
void SysTick_Handler(void){
	if(mode == 1){
	if(counter >= 16){
		prefix = 0xC0;
		t_prefix = 0x80;
	}
	else{
		prefix = 0x80;
		t_prefix = 0xC0;
	}
	if(addr == 14){
		write_to_LCD(prefix + addr,1);
		write_to_LCD(0x20,0);
		write_to_LCD(0,0);
		//write_to_LCD(t_prefix ,1);
		//write_to_LCD(0x37,0);
	}
	else{
		write_to_LCD(prefix + addr,1);
		write_to_LCD(0x20,0);
		write_to_LCD(0x0,0);
		//write_to_LCD(0x37,0);
	}
	addr++;
	addr%=16;
	counter++;
	counter%=32;
	write_to_LCD(0x02,1);
	}
	else{
        timeout = 1;

	}
}
void init_LCD(){
	write_to_LCD(0x38,1);//function setting 00110000
	write_to_LCD(0x06,1);
	write_to_LCD(0x0c,1); //display on  00001110
	write_to_LCD(0x01,1);//clear screen  00000001
	write_to_LCD(0x80,1);//MOVE to top left 0000 0010
}
void EXTI_Setup(){

	RCC->APB2ENR |= 0x1;
	SYSCFG->EXTICR[3] = 0 ;
	SYSCFG->EXTICR[3] |= (uint32_t) 0x20 ;// PC13
	EXTI->IMR1 |= 1 << 13;
	EXTI->RTSR1 = 1 << 13;
	NVIC->ISER[1] |= 1 << 8;
	NVIC_SetPriority(40,-1);
	NVIC_SetPriority(-1,10);
}

void EXTI13_IRQHandler(void){
	//debounce();
	int press = GPIOC->IDR;
	if(mode == 1){
        mode = 2;
        
	}
	else{
		write_to_LCD(0x01,1);

		mode = 1;
	}
	EXTI->PR1 |= 1 << 13; //clear pending
}
void debounce(){
	int k =0 ;
	for(int i=5500;i>=0;i--){
		k++;
	}
}

void write_str_to_LCD(){
	write_to_LCD(0x01,1); //clear display
	count = 0;
	write_to_LCD(0x80,1);

}
void OneWire_Init(OneWire_t* OneWireStruct, GPIO_TypeDef* GPIOx, uint32_t GPIO_Pin) {
	GPIOx->PUPDR |= 1 << (GPIO_Pin * 2); // set pull up
    GPIOx->MODER = 0;                       // set input mode
    OneWireStruct->GPIOx = GPIOx;
    OneWireStruct->GPIO_Pin = GPIO_Pin;
}

/* Send reset through OneWireStruct
 * Please implement the reset protocol
 * param:
 *   OneWireStruct: wire to send
 * retval:
 *    0 -> Reset OK
 *    1 -> Reset Failed
 */
uint8_t OneWire_Reset(OneWire_t* OneWireStruct) {
    OneWireStruct->GPIOx->MODER |= 1 << (OneWireStruct->GPIO_Pin * 2);    //set to output mode
    OneWireStruct->GPIOx->BRR |= 1 << (OneWireStruct->GPIO_Pin); //pull down 
    wait(480);
    OneWireStruct->GPIOx->MODER = 0;    // set to input mode
    wait(60);
    if(OneWireStruct->GPIOx->IDR  & (1 << (OneWireStruct->GPIO_Pin)))
        return 0;
    else
        return 1;
}

/* Write 1 bit through OneWireStruct
 * Please implement the send 1-bit protocol
 * param:
 *   OneWireStruct: wire to send
 *   bit: bit to send
 */
void OneWire_WriteBit(OneWire_t* OneWireStruct, uint8_t bit) {
    wait(1);
    if(bit == 1){
        OneWireStruct->GPIOx->MODER |= 1 << (OneWireStruct->GPIO_Pin * 2);    //set to output mode
        OneWireStruct->GPIOx->BRR |= 1 << (OneWireStruct->GPIO_Pin); //pull down 
        wait(15);
        OneWireStruct->GPIOx->MODER = 0;    // set to input mode
        wait(45);
    }
    
    else{
        OneWireStruct->GPIOx->MODER |= 1 << (OneWireStruct->GPIO_Pin * 2);    //set to output mode
        OneWireStruct->GPIOx->BRR |= 1 << (OneWireStruct->GPIO_Pin); //pull down 
        wait(60):    
    }
    wait(410);
}

/* Read 1 bit through OneWireStruct
 * Please implement the read 1-bit protocol
 * param:
 *   OneWireStruct: wire to read from
 */
uint8_t OneWire_ReadBit(OneWire_t* OneWireStruct) {
    wait(1);
    
}


/* A convenient API to write 1 byte through OneWireStruct
 * Please use OneWire_WriteBit to implement
 * param:
 *   OneWireStruct: wire to send
 *   byte: byte to send
 */
void OneWire_WriteByte(OneWire_t* OneWireStruct, uint8_t byte) {
	// TODO
}

/* A convenient API to read 1 byte through OneWireStruct
 * Please use OneWire_ReadBit to implement
 * param:
 *   OneWireStruct: wire to read from
 */
uint8_t OneWire_ReadByte(OneWire_t* OneWireStruct) {
	// TODO
}

/* Send ROM Command, Skip ROM, through OneWireStruct
 * You can use OneWire_WriteByte to implement
 */
void OneWire_SkipROM(OneWire_t* OneWireStruct) {
	// TODO
}

int main(){
	s_len = strlen(str);
	system_clock_config();
	GPIO_init();
	init_LCD();
	systick_init();
	EXTI_Setup();
	write_to_LCD(0x40,1); //set CG RAM 0100 0000

	write_to_LCD(0x04,0); //0000 0000
	write_to_LCD(0x0E,0); // 0000 1110
	write_to_LCD(0x0E,0); // 0001 0101
	write_to_LCD(0x0E,0);   // 00001 1111
	write_to_LCD(0x1F,0); // 0001 0101
	write_to_LCD(0x00,0); // 0001 1011
	write_to_LCD(0x04,0); //0000 1110
	write_to_LCD(0x00,0);
	//OneWire_t one_wire;
	//OneWire_Init(&one_wire, GPIOA, 7);


}

