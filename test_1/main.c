#ifndef F_CPU
#define F_CPU 16000000UL // or whatever may be your frequency
#endif
 
#include <avr/io.h>
#include <util/delay.h>                // for _delay_ms()
 
int main(void)
{
    DDRB = 0x20;                       // initialize port D
    while(1)
    {
        // LED on
        PORTB = 0x20;            // PD0 = High = Vcc
        _delay_ms(100);                // wait 100 milliseconds
 
        //LED off
        PORTB = 0x00;            // PD0 = Low = 0v
        _delay_ms(100);                // wait 100 milliseconds
    }
}