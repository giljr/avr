/*
 * Project - Ardu_Serie Episode #38
 * Arduino_AVR_Ep_01.c
 *
 * Descriptions: 
 * HELLO WORLD ARDUINO UNO! App; only turns on led on pin 5 of the Arduino B port;
 * To compile Build> Build Solution (F7) and Tools> Being Arduino UNO 
 * (do not forget to run the entire tutorial indicated step 01)
 *
 * Based: Getting Started with AVR: Finding Documentation and Turning on an LED (#2)
 * you tube: https://youtu.be/6JEbnyz2Mac
 *
 * Board: OPEN-SMART UNO (ARDUINO UNO compatible)
 * https://drive.google.com/drive/u/0/folders/0B6uNNXJ2z4Cxc3VwZHNaUkM3eGs
 *
 * WebPage: Atmel Studio 7 & UNO Serie (Ep#00) @giljrE 
 * https://medium.com/series/atmel-studio-7-uno-ep-00-969b9cc3cf7b
 *
 * Created: 24/05/2018 07:11:15
 * Author : J3
 */ 

#include <avr/io.h>


int main(void)
{
	                  /* PORTB Data Register - DS pg 92 */
    DDRB |= (1<<DDB5);
	
	                 /* just turns pin 5 of Port B on forever */
    while (1) 
    {		
                     /* Set Pin 5 high */
		PORTB |= (1<<PORTB5); 
    }
}

