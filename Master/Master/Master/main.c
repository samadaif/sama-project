/*
 * Master.c
 *
 * Created: 9/30/2021 2:17:54 PM
 * Author : sama youssef
 */ 

//macros [including header files]
#include "UART.h"  
#include "SPI.h"
#include "LED.h"

int main()
{
//initializations 
UART_Init();  
SPI_Init();
LED0_Initialization();
LED1_Initialization();
LED2_Initialization();

uint8_t data; //uninitialized global variable to store data received by UART

	while(1)
	{	 data = UART_Receive(); 
		
		if (data == '1') //if data received by UART is [1], then toggle the first led
		{	
		LED0_TGL();
		SPI_Transmit(data); //transmit this data from the master to slave using SPI
		}
		
		else if (data == '2') //if data received by UART is [2], then toggle the second led
		{
			LED1_TGL(); 
			SPI_Transmit(data); //transmit this data from the master to slave using SPI
		}
		
		else if (data == '3') //if data received by UART is [3], then toggle the third led
		{
			LED2_TGL();
			SPI_Transmit(data); //transmit this data from the master to slave using SPI
		}
		
	}
			
		
		
		
		
	
	
	
	
}

