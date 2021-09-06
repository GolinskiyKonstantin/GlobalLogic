
#include "stm32f303xc.h"

// In the code we will use USART1   RX -> PC5     TX -> PC4


// function prototypes
void uart_init(void);
void uart_open(void);
uint8_t uart_read(void);
void uart_write(uint8_t dt);
void uart_close(void);
void uart_deinit(void);


int main(void)
{
	// initialize USART1
	uart_init();
	uart_open();

	// create a string and send it byte by byte to USART1
	char arr[] = "GlobalLogic\r\n";

	for(uint8_t i = 0; i < sizeof(arr); i++){
		uart_write( arr[i] );
	}

	while( 1 ){

		// read data
		uint8_t value = uart_read();

		// we send back what we received
		uart_write( value );

		//functions uart_close() and uart_deinit() can be called at any time where we need it
	}

}




//====================================================================================================

// initialize USART1 ( turn on clocking and alternative function )
void uart_init(void)
{
	// Enable clock to USART1
	RCC->APB2ENR |= RCC_APB2ENR_USART1EN;	// RCC->APB2ENR |= (0x00000001U << 14);

	// Enable clock to GPIOC
	RCC->AHBENR |= RCC_AHBENR_GPIOCEN;		// RCC->AHBENR |= (0x00000001U << 19);

	// Enable pins for alternative functions ( PC4, PC5 )
	GPIOC->MODER |= GPIO_MODER_MODER4_1; 	// GPIOC->MODER |= (0x00000001U << 9); 	// PC4 ( GPIO_MODER_MODER4 == 11, GPIO_MODER_MODER4_0 == 01, GPIO_MODER_MODER4_1 == 10 )
	GPIOC->MODER |= GPIO_MODER_MODER5_1;	// GPIOC->MODER |= (0x00000001U << 11); // PC5 ( GPIO_MODER_MODER5 == 11, GPIO_MODER_MODER5_0 == 01, GPIO_MODER_MODER5_1 == 10 )


	// Configure type of alternative function ( PC5, PC4 ) AF7 DataSheet page 49 Table 16. Alternate functions for port C
	GPIOC->AFR[0] |= (0x00000007UL << GPIO_AFRL_AFRL4_Pos);		// 0x00000007 << 16
	GPIOC->AFR[0] |= (0x00000007UL << GPIO_AFRL_AFRL5_Pos);		// 0x00000007 << 20
}

// settings USART1
void uart_open(void)
{
	// Configure USART1
	USART1->BRR = 8000000 / 115200; 							// HSI 8000000Hz / 115200 baud
	USART1->CR1 |= USART_CR1_TE | USART_CR1_RE | USART_CR1_UE; 	// USART1->CR1 |= 0x0000000C; 	// Enable TX, RX, 8-bit data.  Enable USART1
	USART1->CR2 = 0x00000000UL;
	USART1->CR3 = 0x00000000UL;
}


// This polling mode function waits until the read data register is empty by checking the RXNE flag ( 5 bit )
// in the ISR and returns the received data
uint8_t uart_read(void)
{
	while(!(USART1->ISR & USART_ISR_RXNE)) { asm("nop"); }
	return (uint8_t)USART1->RDR;
}

// This polling mode function waits until the transmit data register is empty by checking the TXE flag ( 7 bit )
// in the register ISR and transfers new data
void uart_write(uint8_t dt)
{
	while(!(USART1->ISR & USART_ISR_TXE)) { asm("nop"); }
	USART1->TDR = (uint16_t)dt;
}

// reset the registers, reset settings USART1
void uart_close(void)
{
	USART1->BRR = 0x00000000UL;
	USART1->CR1 = 0x00000000UL;
	USART1->CR2 = 0x00000000UL;
	USART1->CR3 = 0x00000000UL;
}

// disable clocking and alternative function USART1
void uart_deinit(void)
{
	// Reset configuration of alternative function
	GPIOC->AFR[0] &= ~(0x00000007UL << GPIO_AFRL_AFRL4_Pos);
	GPIOC->AFR[0] &= ~(0x00000007UL << GPIO_AFRL_AFRL5_Pos);

	// Disable pins for alternative functions, PC4, PC5
	GPIOC->MODER &= ~(GPIO_MODER_MODER4_1);
	GPIOC->MODER &= ~(GPIO_MODER_MODER5_1);

	// Disable clock access to GPIOC (bit 19)
	RCC->AHBENR &= ~(RCC_AHBENR_GPIOCEN);

	// Disable clock access to USART1
	RCC->APB2ENR &= ~(RCC_APB2ENR_USART1EN);
}

