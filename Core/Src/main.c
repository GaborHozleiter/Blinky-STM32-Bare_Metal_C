#include "stm32g0xx.h";

int main(void){

	// ---------------- Clock Configuration -------------------------------------
	// Enable GPIOA as GPIOC clocks
	RCC->IOPENR |= (1U << 0) | (1U << 2);

	// ---------------- GPIO Configuration --------------------------------------
	// Configure PA5 as output (LED pin)
	GPIOA->MODER &= ~((1U << 11) | (1U << 10));

	GPIOA->MODER |= (1U << 10);


	// Configure PA13 as input (user button)
	GPIOC->MODER &= ~((1U << 27) | (1U << 26));

	// ------------------ LED Control -------------------------------------------
	// Turn LED on (PA5 high)
	GPIOA->BSRR = (1U << 5);

}
