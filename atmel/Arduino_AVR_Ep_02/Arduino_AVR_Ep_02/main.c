/*
 * Project - Ardu_Serie Episode #42
 * Arduino_AVR_Ep_02.c
 *
 * Descriptions: 
 * Introducing AVR LibC we gonna toggle the led on pin 13 (same as PINB5); after that
 * To compile Build> Build Solution (F7) and Tools> Being Arduino UNO 
 * (do not forget to run the entire tutorial indicated step 01)
 *
 * Based: Getting Started with AVR: Finding Documentation and Turning on an LED (#3)
 * you tube:  *https://youtu.be/aeXMPVQ3MuM
 *
 * Board: OPEN-SMART UNO (ARDUINO UNO compatible)
 * https://drive.google.com/drive/u/0/folders/0B6uNNXJ2z4Cxc3VwZHNaUkM3eGs
 * 
 * Datasheet: https://www.sparkfun.com/datasheets/Components/SMD/ATMega328.pdf
 *
 * WebPage: Atmel Studio 7 & UNO Serie (Ep#00) @giljrE 
 * https://medium.com/series/atmel-studio-7-uno-ep-00-969b9cc3cf7b
 *
 * Created: 25/05/2018 15:58:10
 * Author : J3
 */ 

#define F_CPU 16000000UL /* 16MHz Frequency Working Arduino UNO Clock */
#include <avr/io.h>
#include <util/delay.h> /* Include a AVR LibC functions*/


int main(void)
{
	                  /* PORTB Data Register - DS pg 92 */
    DDRB |= (1<<DDB5);
	
	                 /* just turns pin 5 of Port B on forever */
    while (1) 
    {		
                     /* 11.2.2 Toggling the Pin (DS pg 77)
                     Writing a logic one to PINxn toggles the value of PORTxn, independent on the value of DDRxn.
                     Note that the SBI instruction can be used to toggle one single bit in a port.*/
		PINB |= (1<<PINB5); 
		_delay_ms(500);
    }
}
