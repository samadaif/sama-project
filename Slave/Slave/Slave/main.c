/*
 * Slave.c
 *
 * Created: 9/30/2021 2:57:59 PM
 * Author : sama youssef
 */ 

//macros [including header files]
#include "SPI.h"
#include "UART.h"
#include "LED.h"


int main(void)
{	//initializations
	SPI_Init();
	UART_Init();
	LED0_Initialization();
	LED1_Initialization();
	LED2_Initialization();
	
	uint8_t data; //uninitialized global variable to store data received by SPI
	
    
    while (1) 
    {
		data = SPI_Receive();
		
		if(data == '1') //if data received by SPI is [1] , toggle first led
		{
			LED0_TGL();
		}
		
		else if(data == '2')//if data received by SPI is [2] , toggle second led
		{
			LED1_TGL();
		}
		
		else if(data == '3')//if data received by SPI is [3] , toggle third led
		{
			LED2_TGL();
		}
		
		
 
    }
}

