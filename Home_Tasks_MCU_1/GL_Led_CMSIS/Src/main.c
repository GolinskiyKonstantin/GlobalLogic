
#include "stm32f303xc.h"

// variable for counting system ticks
__IO uint32_t counter = 0U;

// override the function of counting system ticks
void SysTick_Handler(){
	if(counter){ counter--; }
}

// delay function (in milliseconds)
void delay_ms(uint32_t ms){
	counter = ms;
	while(counter){ asm("nop"); };
}

int main(void)
{

	RCC->AHBENR |= RCC_AHBENR_GPIOEEN;		// RCC->AHBENR |= (0x00000001U << 21);		// AHB enables clocking of the port E (GPIOE)

	GPIOE->MODER |= GPIO_MODER_MODER8_0;	// GPIOE->MODER |= (0x00000001U << 16);	// pin 8 General purpose output mode	( GPIO_MODER_MODER8 == 11, GPIO_MODER_MODER8_0 == 01, GPIO_MODER_MODER8_1 == 10 )
	GPIOE->MODER |= GPIO_MODER_MODER9_0;	// GPIOE->MODER |= (0x00000001U << 18);	// pin 9 General purpose output mode	( GPIO_MODER_MODER9 == 11, GPIO_MODER_MODER9_0 == 01, GPIO_MODER_MODER9_1 == 10 )
	GPIOE->MODER |= GPIO_MODER_MODER10_0;	// GPIOE->MODER |= (0x00000001U << 20);	// pin 10 General purpose output mode	( GPIO_MODER_MODER10 == 11, GPIO_MODER_MODER10_0 == 01, GPIO_MODER_MODER10_1 == 10 )
	GPIOE->MODER |= GPIO_MODER_MODER11_0;	// GPIOE->MODER |= (0x00000001U << 22);	// pin 11 General purpose output mode	( GPIO_MODER_MODER11 == 11, GPIO_MODER_MODER11_1 == 01, GPIO_MODER_MODER11_1 == 10 )
	GPIOE->MODER |= GPIO_MODER_MODER12_0;	// GPIOE->MODER |= (0x00000001U << 24);	// pin 12 General purpose output mode	( GPIO_MODER_MODER12 == 11, GPIO_MODER_MODER12_0 == 01, GPIO_MODER_MODER12_1 == 10 )
	GPIOE->MODER |= GPIO_MODER_MODER13_0;	// GPIOE->MODER |= (0x00000001U << 26);	// pin 13 General purpose output mode	( GPIO_MODER_MODER13 == 11, GPIO_MODER_MODER13_0 == 01, GPIO_MODER_MODER13_1 == 10 )
	GPIOE->MODER |= GPIO_MODER_MODER14_0;	// GPIOE->MODER |= (0x00000001U << 28);	// pin 14 General purpose output mode	( GPIO_MODER_MODER14 == 11, GPIO_MODER_MODER14_0 == 01, GPIO_MODER_MODER14_1 == 10 )
	GPIOE->MODER |= GPIO_MODER_MODER15_0;	// GPIOE->MODER |= (0x00000001U << 30);	// pin 15 General purpose output mode	( GPIO_MODER_MODER15 == 11, GPIO_MODER_MODER15_0 == 01, GPIO_MODER_MODER15_1 == 10 )

	// we calculate the clock cycles, from the clocking of the internal RC generator, the frequency of which is 8 MHz
	SysTick_Config(8000000/1000);

	while(1) {

		// LEDs on
		GPIOE -> BSRR = GPIO_BSRR_BS_8 | GPIO_BSRR_BS_9 | GPIO_BSRR_BS_10 | GPIO_BSRR_BS_11 | GPIO_BSRR_BS_12 | GPIO_BSRR_BS_13 | GPIO_BSRR_BS_14 | GPIO_BSRR_BS_15;	// SET ( HIGH )

		delay_ms(1000);

		// LEDs off
		GPIOE -> BSRR = GPIO_BSRR_BR_8 | GPIO_BSRR_BR_9 | GPIO_BSRR_BR_10 | GPIO_BSRR_BR_11 | GPIO_BSRR_BR_12 | GPIO_BSRR_BR_13 | GPIO_BSRR_BR_14 | GPIO_BSRR_BR_15;;	// RESET ( LOW )

		delay_ms(1000);
	}

}

