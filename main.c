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
	GPIOC->MODER = (GPIOC->MODER & 0xf3fffff0) | 0xA;
	GPIOC->AFR[0] = (GPIOC->AFR[0] & 0xffffff00) | 0x77;
}


void SysTick_Handler(void){


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
	EXTI->PR1 |= 1 << 13; //clear pending
}
void debounce(){
	int k =0 ;
	for(int i=5500;i>=0;i--){
		k++;
	}
}

void USART1_init(void){
	RCC->APB2ENR |= 1 << 14;
	USART1->CR1 |= USART_CR1_TE;
	USART1->CR1 |= USART_CR1_RE;
	USART1->BRR |= 0x1A0;
	USART1->CR2 &= ~(USART_CR2_LINEN | USART_CR2_CLKEN);
	USART1->CR3 &= ~(USART_CR3_SCEN | USART_CR3_HDSEL | USART_CR3_IREN);
	USART1->CR1 |= USART_CR1_UE;

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

