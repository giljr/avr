/*
 * Project - Ardu_Serie Episode #5
 * Arduino_AVR_Ep_05.c
 *
 * Descriptions: In the last post we used a pin change interrupt to detect wheather 
 * a switch was pressed. Now the main benefit of using interrupts as opposed to polling
 * is that we're not keeping the processor occupied just with one task but besides to 
 * be able to put the CPU down to low-power and reduce dramatically the power consumption 
 * of an application. It's particularly important for battery-driven app and the like.
 * Now low-power is really one of Atmel core's technologies.
 * In this code we will apply one of this technology to put the processor in sleep mode!
 * Let's get started!
 * The idea is when the Touch button (Arduino Pin 7) is pressed it wakes the system up!
 * We will use the LED on PORTB0 (Arduino Pin 8);
 * To compile Build> Build Solution (F7) and Tools> Being Arduino UNO 
 * (do not forget to run the entire tutorial indicated Episode #01)
 *
 * Based: Getting Started with AVR: Finding Documentation and Turning on an LED (#5)
 * you tube:  https://youtu.be/w37FOUrXO6s
 *
 * Board: OPEN-SMART UNO (ARDUINO UNO compatible)
 * https://drive.google.com/drive/u/0/folders/0B6uNNXJ2z4Cxc3VwZHNaUkM3eGs
 * 
 * Datasheet: https://www.sparkfun.com/datasheets/Components/SMD/ATMega328.pdf
 * 
 * avr-libc: https://www.nongnu.org/avr-libc/user-manual/group__util__delay.html
 *
 * AVRFreaks: https://www.avrfreaks.net/
 *
 * WebPage: https://medium.com/series/atmel-studio-7-uno-ep-00-969b9cc3cf7b
 *
 * Created: 29/05/2018 16:11:10
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

ISR(PCINT2_vect)
{
			if (SWITCH_PRESSED)
			{
				     LedOn;
			} else
			{
					LedOff;
			}						
}


int main(void)
{
	                         /* PORTB Data Register - DS pg 92 */
    DDRB |=  (1<<DDB0);      /* LED Attach -> Pin 0 of PORTB (Arduino Digital 8) */
	DDRD &= ~(1<<DDD7);      /* Switch Key -> Pin 7 of PORTD (Arduino Digital 7) */
	
	PRR =0xFF;               /* Desable all peripherals  */
	                         /* Set sleep mode */
							 /* The 6 different modes are (sleep.h):
							    SLEEP_MODE_IDLE?-?the least power savings
							    SLEEP_MODE_ADC
							    SLEEP_MODE_PWR_SAVE
							    SLEEP_MODE_STANDBY
							    SLEEP_MODE_EXT_STANDBY
							    SLEEP_MODE_PWR_DOWN?-?the most power savings 
								*/
	set_sleep_mode(SLEEP_MODE_PWR_DOWN);        
	
	PCMSK2 |= (1<<PCINT23);	 /* Pin Change Mask Register 2 on Arduino Pin 7 I/O - pg 94 */
	PCICR |= (1<< PCIE2);    /* bit selects whether pin change interrupt is enabled */
	
	sei();                   /* Enable interrupt by setting the global interrupt mask */
	
	                         /* Polling Pin 7 PORTD */
    while (1) 
    {		
                             /* Transferring the switching LED status to ISR */	
		
    }
}