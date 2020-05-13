#include "stm32f10x.h"

void pause(int time){
	for(int i=0;i<time;++i){}
}

void gpioabegin(){
	RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
	
	GPIOC->CRL &=~ (GPIO_CRL_CNF0 | GPIO_CRL_MODE0);
  GPIOC->CRL |= GPIO_CRL_MODE0_1;

	GPIOC->CRL &=~ (GPIO_CRL_CNF1 | GPIO_CRL_MODE1);
  GPIOC->CRL |= GPIO_CRL_MODE1_1;	
}

void forward(){
	GPIOC->BSRR = GPIO_BSRR_BS0;
	GPIOC->BSRR = GPIO_BSRR_BR1;
}
void back(){
	GPIOC->BSRR = GPIO_BSRR_BS1;
	GPIOC->BSRR = GPIO_BSRR_BR0;
}
void stop(){
	GPIOC->BSRR = GPIO_BSRR_BS1;
	GPIOC->BSRR = GPIO_BSRR_BS0;
}
int main (){
	uint16_t i=0;
	gpioabegin();
	while(1){
		back();
		pause(150000);
		stop();
		pause(15000);
		break;
	}
}