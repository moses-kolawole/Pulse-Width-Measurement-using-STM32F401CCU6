#include "main.h"

int main(void){

	RCC->AHB1ENR |= (1 << 0);

	// Setting PA0
	GPIOA->MODER &= ~(3 << (0 * 2));
	GPIOA->MODER |=  (2 << (0 * 2));

	// Select AF1 for PA0 (TIM2_CH1)
	GPIOA->AFR[0] &= ~(0xF << (0 * 4));
	GPIOA->AFR[0] |=  (1 << (0 * 4));

	// Setting PA6
	GPIOA->MODER &= ~(3 << (6 * 2));
	GPIOA->MODER |=  (2 << (6 * 2));

	// Select AF2 for PA6 (TIM3_CH1)
	GPIOA->AFR[0] &= ~(0xF << (6 * 4));
	GPIOA->AFR[0] |=  (2 << (6 * 4));

	// Enable TIM2 Clock
	RCC->APB1ENR |= (1 << 0);

	// Enable TIM3 Clock
	RCC->APB1ENR |= (1 << 1);

	// Set the Prescaler
	TIM2->PSC = 15;

	// Set the ARR
	TIM2->ARR = 999;

	// Reset the Timer
	TIM2->CNT = 0;

	// Configure Channel 1 as Input Capture
	TIM2->CCMR1 &= ~(3 << 0);
	TIM2->CCMR1 |=  (1 << 0);

	// Capture on Rising Edge
	TIM2->CCER &= ~(1 << 1);

	// Enable Capture Channel
	TIM2->CCER |= (1 << 0);

	// Start the Timer
	TIM2->CR1 |= (1 << 0);

	while(1)
	{

	}

	return 0;
}
