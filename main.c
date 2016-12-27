#include <stdint.h>
#include "stm32l476xx.h"
#include "core_cm4.h"
#include <string.h>

#define LCD_RSPin 1
#define LCD_RWPin 5
#define LCD_ENPin 6

int systick_count = 0;

extern void delay(int s);

void systick_init(){
	SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
	SysTick->CTRL |= SysTick_CTRL_TICKINT_Msk;
	SysTick->CTRL |= SysTick_CTRL_CLKSOURCE_Msk;
	SysTick->LOAD = (uint32_t) 6000000;
}
void system_clock_config(){
		// 10M Hz
		RCC->CFGR &= 0xfffff000;
		RCC->CR &= 0xFEFFFFFF;
		while((RCC->CR & RCC_CR_PLLRDY) > 0);
		RCC->PLLCFGR &= 0xf9ff808f;
		RCC->PLLCFGR |= 2; //set clock source
		RCC->PLLCFGR |= RCC_PLLCFGR_PLLN_2;
		RCC->PLLCFGR |= RCC_PLLCFGR_PLLN_3;
        RCC->PLLCFGR |= RCC_PLLCFGR_PLLN_4;
		RCC->PLLCFGR |= RCC_PLLCFGR_PLLN_5;
        RCC->PLLCFGR |= RCC_PLLCFGR_PLLM_1;
		RCC->PLLCFGR |= RCC_PLLCFGR_PLLR_0;
		RCC->PLLCFGR |= RCC_PLLCFGR_PLLR_1;
		RCC->CR |= RCC_CR_PLLON;
		RCC->CR |= RCC_CR_HSION;
		RCC->PLLCFGR |= RCC_PLLCFGR_PLLREN;
		RCC->CFGR |= 15;
}
void GPIO_init(){
	RCC->AHB2ENR = RCC->AHB2ENR | 0xf;
<<<<<<< Updated upstream

	GPIOC->MODER = (GPIOC->MODER & 0xf3ffffff);

	GPIOB->MODER =  (GPIOB->MODER & 0xffff0000) |0x5555 ;
	GPIOB->PUPDR = (GPIOB->PUPDR & 0xffff0000) | 0xAAAA;
	GPIOB->OSPEEDR = (GPIOB->OSPEEDR & 0xffff0000) | 0x5555;
	GPIOB->OTYPER = 0;

	GPIOA->MODER =  (GPIOA->MODER & 0xffff0000) |0x5555 ;
	GPIOA->PUPDR = (GPIOA->PUPDR & 0xffff0000) | 0xAAAA;
	GPIOA->OSPEEDR = (GPIOA->OSPEEDR & 0xffff0000) | 0x5555;
	GPIOA->OTYPER = 0;

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
int wait(){
	int k=0;
	for(int i=0;i<50000;i++){
		k++;
	}
	return 1;
}
=======
	GPIOC->MODER = (GPIOC->MODER & 0xf3fffff0) | 0xA;
	GPIOC->AFR[0] = (GPIOC->AFR[0] & 0xffffff00) | 0x77;
}


>>>>>>> Stashed changes
int addr=0;
int prefix = 0x80;
int t_prefix = 0xC0;
int counter = 0;
int mode = 1;
int count;
void SysTick_Handler(void){
<<<<<<< Updated upstream
	systick_count++;
	if(mode == 1){
		if(systick_count < 2)
			return;
		systick_count = 0;
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
			write_to_LCD(t_prefix ,1);
			write_to_LCD(0x01,0);
		}
		else if(addr == 15){
			write_to_LCD(prefix + addr,1);
			write_to_LCD(0x20,0);
			write_to_LCD(t_prefix ,1);
			write_to_LCD(0,0);
			write_to_LCD(0x01,0);
		}

		else{
			write_to_LCD(prefix + addr,1);
			write_to_LCD(0x20,0);
			write_to_LCD(0x0,0);
			write_to_LCD(0x01,0);
		}
		addr++;
		addr%=16;
		counter++;
		counter%=32;
		write_to_LCD(0x02,1);
	}
	else{
		if(systick_count < 4)
			return;
		systick_count = 0;
		get_temp();
	}
}
void init_LCD(){
	write_to_LCD(0x38,1);//function setting 00110000
	write_to_LCD(0x06,1);
	write_to_LCD(0x0c,1); //display on  00001110
	write_to_LCD(0x01,1);//clear screen  00000001
	write_to_LCD(0x80,1);//MOVE to top left 0000 0010
=======

>>>>>>> Stashed changes
}

void EXTI_Setup(){
	RCC->APB2ENR |= 0x1;
	SYSCFG->EXTICR[3] = 0 ;
	SYSCFG->EXTICR[3] |= (uint32_t) 0x20 ;// PC13
	EXTI->IMR1 |= 1 << 13;
	EXTI->RTSR1 = 1 << 13;
	NVIC->ISER[1] |= 1 << 8;
	NVIC_SetPriority(40,-2);
	NVIC_SetPriority(-1,10);
}

void EXTI13_IRQHandler(void){
<<<<<<< Updated upstream
	write_to_LCD(0x01,1);
	if(mode == 1){
        mode = 2;
	}
	else{
		mode = 1;
	}
	write_to_LCD(0x01,1);
=======

>>>>>>> Stashed changes
	EXTI->PR1 |= 1 << 13; //clear pending
}
void debounce(){
	int k =0 ;
	for(int i=5500;i>=0;i--){
		k++;
	}
}

<<<<<<< Updated upstream
void display(int temp){
	temp *= 625;
	int c = 0;
	write_to_LCD(0x80, 1);
	int arr[12];
	while(temp != 0){
		if (c==4){
			arr[c] =  0x2E;
			c++;
		}
		arr[c] = 0x30 +(temp % 10);
		c++;
		temp /= 10;
	}
	for(int i=c-1;i>-1;i--){
		write_to_LCD(arr[i], 0);
	}
=======

void USART1_init(void){
	RCC->APB2ENR |= 1 << 14;
	USART1->CR1 |= USART_CR1_TE;
	USART1->CR1 |= USART_CR1_RE;
	USART1->BRR |= 0x1A0;
	USART1->CR2 &= ~(USART_CR2_LINEN | USART_CR2_CLKEN);
	USART1->CR3 &= ~(USART_CR3_SCEN | USART_CR3_HDSEL | USART_CR3_IREN);
	USART1->CR1 |= USART_CR1_UE;
>>>>>>> Stashed changes
}
/*int UART_transmit(uint8_t *arr, uint32_t ){
	while()
}*/
void USART_PutChar(uint8_t ch)
{
  while(!(USART1->ISR & (1<<7)));
  USART1->TDR = ch;
}
int main(){
	//system_clock_config();
	GPIO_init();
	USART1_init();
	USART_PutChar('A');
	//EXTI_Setup();



	//systick_init();

}

