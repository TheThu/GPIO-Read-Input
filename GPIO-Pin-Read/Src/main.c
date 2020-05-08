/**
 ******************************************************************************
 * @file           : main.c
 * @author         : The Thu Tran
 * @brief          : Bit extraction
 ******************************************************************************
*/

#include <stdint.h>

int main(void)
{
	// Enable AHB peripheral clock enable register (RCC_AHBENR) for GPIOA
	uint32_t *pRCC_AHBENR = (uint32_t*)0x40021014;
	*pRCC_AHBENR|=1<<17;




	// Enable  GPIO port mode register (GPIOA_MODER) General purpose output mode for GPIOA Pin5
	uint32_t *pGPIOA_MODER =(uint32_t*)0x48000000;
	*pGPIOA_MODER|=(1<<10); // Output Mode
	*pGPIOA_MODER |=(3<<20); // Input Mode
	*pGPIOA_MODER &= ~(3<<20); // Input Mode


	// Assigning GPIO port output data register (GPIOA_ODR) to pointer
	uint32_t *pGPIOA_ODR = (uint32_t*) 0x48000014;
	// Assigning GPIO port input data register (GPIOA_ODR) to pointer
	uint32_t *pGPIOA_IDR = (uint32_t*) 0x48000010;




	uint32_t status=0;

	while(1){
		// Bit extraction out of Input register of PA10
		status = (*pGPIOA_IDR >> 10)& 1;

		// Check whether status is HIGH or LOW
		if (status)
		{
			// Turn on LD2
			*pGPIOA_ODR|=(1<<5);
			//status = 0;
		}

		else{
			*pGPIOA_ODR&=~(1<<5);
		}

	}


}
