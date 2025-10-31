#include "stm32g0xx.h"

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


	// Activate internal pull-up for PC13
	GPIOC->PUPDR &= ~((1U << 26) | (1U << 27));

	GPIOC->PUPDR |= (1U << 26);



	// Start the main application loop
	while(1){

	// Check for the button press
	if (!(GPIOC->IDR & (1U << 13))) {

		// Simple delay for debouncing the button press
		for(int i=0; i<50000; i++){}

		// Check again after the delay
		if (!(GPIOC->IDR & (1U << 13))) {
					// ------------------ LED Control -------------------------------------------
						// Turn LED on (PA5 high)
						GPIOA->BSRR = (1U << 5);
				}
			else {

				// ------------------ LED Control -------------------------------------------
				// Turn LED off (PA5 low)
			GPIOA->BSRR = (1U << 21);
			}
		}
	else {

		// Simple delay for debouncing the button press
		for(int i=0; i<50000; i++){}

		// Check again after the delay
		if ((GPIOC->IDR & (1U << 13))) {

			// ------------------ LED Control -------------------------------------------
			// Turn LED off (PA5 low)
			GPIOA->BSRR = (1U << 21);
			}
	}
	}

}
