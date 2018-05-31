/*
 * Project - Ardu_Serie Episode #6
 * Arduino_AVR_Ep_06.c
 *
 * Descriptions: We're gonna start with a new peripheral: Timer Counter!
 * But now let's toggle LED at every 5 milliseconds using Timer counter Zero or One.
 * We are going to start off where we were in previous episode #05 
 * (we have an interruption generated when we push the button:)
 * Let's get started!
 * We will use the LED on PORTB0 (Arduino Pin 8) toggle every 5 seconds; for it we use Timer1.
 * To compile Build> Build Solution (F7) and Tools> Being Arduino UNO 
 * (do not forget to run the entire tutorial indicated Episode #01)
 *
 * Based: Getting Started with AVR: Finding Documentation Using Timer Overflow IRQs (#7)
 * you tube:  https://youtu.be/pXWrk1TH71E
 *
 * Board: OPEN-SMART UNO (ARDUINO UNO compatible)
 * https://drive.google.com/drive/u/0/folders/0B6uNNXJ2z4Cxc3VwZHNaUkM3eGs
 *   or
 * Arduino UNO https://www.arduino.cc/
 * 
 * Data sheet:
 * http://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-8271-8-bit-AVR-Microcontroller-ATmega48A-48PA-88A-88PA-168A-168PA-328-328P_datasheet_Complete.pdf
 * 
 * avr-lib c: https://www.nongnu.org/avr-libc/user-manual/group__util__delay.html
 *
 * AVRFreaks: https://www.avrfreaks.net/
 *
 * WebPage: https://medium.com/series/atmel-studio-7-uno-ep-00-969b9cc3cf7b
 *
 * Created: 31/05/2018 13:39:10
 * Author : J3
 *
 ** Terms of use:                                                                **
 ** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR   **
 ** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,     **
 ** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  **
 ** AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER       **
 ** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,**
 ** OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN    **
 ** THE SOFTWARE.                                                                **
 */ 

#define F_CPU 16000000UL     /* 16MHz Frequency Working Arduino UNO Clock */
#include <avr/io.h>
#include <util/delay.h>      /* Include a AVR LibC functions*/
#include <avr/interrupt.h>   /* this was included on Episode #04 */
#include <avr/sleep.h>       /* this was included on Episode #05 */


                             /* Defining the basics macros*/
#define LedOn PORTB |= (1<<PORTB0)
#define LedOff PORTB &= ~(1<<PORTB0)
#define LedToggle PINB |= (1<<PINB0)
#define SWITCH_PRESSED !(PIND & (1<<PIND7))
                           
						    
						     /* Now the LED is toggle automatically at each 5 secs
							    and respond by pressing the button:)
						     */
ISR(TIMER1_OVF_vect) 
{
   LedToggle;
} 
 
                             /* This interrupt is raised if you press the button connected 
							    to pin 7 of the Arduino ;)							
						     */ 
//ISR(PCINT2_vect)
//{
//			if (SWITCH_PRESSED)
//			{
//				     LedOn;
//			} else
//			{
//					LedOff;
//			}						
//}


int main(void)
{  
	/**************************         I/O Routines         **************************/
	                         /* PORTB Data Register - DS pg 92 */
    DDRB |=  (1<<DDB0);      /* LED Attach -> Pin 0 of PORTB (Arduino Digital 8) */
	DDRD &= ~(1<<DDD7);      /* Switch Key -> Pin 7 of PORTD (Arduino Digital 7) */
	
	
	/**************************  Timer 1 Interrupt Routines  **************************/	
	TCCR1B |=   (1 << CS12); /* Set scale to 256 */
	                         /* Overflow formula:
								foc = 16000000/2*256*[1+65535]
								foc = 0,476837158203125 secs
								(It overflows roughly twice a second!)
                             */
		
	TIMSK1 |= (1 << TOIE1);  /* Enable Timer1 interrupt */
	
	
	/**************************    Sleep Mode    Routines    **************************/     	
	//PRR =0xFF;               /* Disable all peripherals  */
	                         /* Set sleep mode */
			                 /* The 6 different modes are (sleep.h):
								SLEEP_MODE_IDLE?-?the least power savings
								SLEEP_MODE_ADC
								SLEEP_MODE_PWR_SAVE
								SLEEP_MODE_STANDBY
								SLEEP_MODE_EXT_STANDBY
								SLEEP_MODE_PWR_DOWN?-?the most power savings 
							 */
	//set_sleep_mode(SLEEP_MODE_PWR_DOWN);   
	     
	
	/************************* Pin Change Interrupt Routines **************************/ 
	PCMSK2 |= (1<<PCINT23);  /* Pin Change Mask Register 2 on Arduino Pin 7 I/O - pg 94 */
	PCICR |= (1<< PCIE2);    /* bit selects whether pin change interrupt is enabled */
	
	
	sei();                   /* Enable interrupt by setting the global interrupt mask */
	
	                         /* Polling Pin 7 PORTD */
    while (1) 
    {		
                             /* Calling sleep mode */
	    //sleep_mode();
	    
		
    }
}