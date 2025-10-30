#include "stm32g0xx.h";

int main(void){

	RCC->IOPENR |= (1U << 0) | (1U << 2);

	GPIOA->MODER &= ~((1U << 11) | (1U << 10));

	GPIOC->MODER &= ~((1U << 27) | (1U << 26));

	GPIOA->MODER |= (1U << 10);

	GPIOA->BSRR = (1U << 5); //

}
