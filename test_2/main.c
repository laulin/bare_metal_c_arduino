#ifndef F_CPU
#define F_CPU 16000000UL
#endif
 
#include <avr/io.h>
#include <util/delay.h>

#define LED (0x020)
#define BUTTON (0x10)

int main(void)
{
    DDRB = LED;
    PORTB = BUTTON;

    while(1)
    {
        if (PINB & BUTTON)
        {
            PORTB |= LED;
        }
        else
        {
            PORTB &= ~LED;
        }

        _delay_ms(10);
    }
}