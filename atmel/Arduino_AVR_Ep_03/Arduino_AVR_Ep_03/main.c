/*
 * Project - Ardu_Serie Episode #43
 * Arduino_AVR_Ep_03.c
 *
 * Descriptions: Polling Technique
 * By pressing the Touch button (Arduino Pin 7), turn on LED (Arduino Pin 8);
 * To compile Build> Build Solution (F7) and Tools> Being Arduino UNO 
 * (do not forget to run the entire tutorial indicated Episode #01)
 *
 * Based: Getting Started with AVR: Finding Documentation and Turning on an LED (#4)
 * you tube:  https://youtu.be/mXPyRF-_Y1E
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
 * Created: 25/05/2018 21:56:10
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

#define F_CPU 16000000UL /* 16MHz Frequency Working Arduino UNO Clock */
#include <avr/io.h>
#include <util/delay.h>  /* Include a AVR LibC functions*/
                         /* Defining the basics macros*/
#define LedOn PORTB |= (1<<PORTB0)
#define LedOff PORTB &= ~(1<<PORTB0)
#define LedToggle PINB |= (1<<PINB0)



int main(void)
{
	                     /* PORTB Data Register - DS pg 92 */
    DDRB |=  (1<<DDB0);  /* LED Attach -> Pin 0 of PORTB (Arduino Digital 8) */
	DDRD &= ~(1<<DDD7);  /* Switch Key -> Pin 7 of PORTD (Arduino Digital 7) */
	
	                     /* Polling Pin 7 PORTD */
    while (1) 
    {		
                         /* Active State - Low */
		if (!(PIND & (1<<PIND7)))
		{
			LedOn;
		} else
			LedOff;
		{
	}
		
    }
}