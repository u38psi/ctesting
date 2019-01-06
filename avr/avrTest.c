#include "avr/io.h"
#include "avr/interrupt.h"

#define F_CPU 16000000

uint8_t dutyCycle = 0;

int main()
{
	DDRB |= (1 << PORTB3) | (1 << PORTB4);

	TCCR0A |= (1 << COM0A1) | (1 << COM0B1) | (1 << WGM1) | (1 << WGM0);
	
	TIMSK0 |= (1 << TOIE0);

	OCR0A = (dutyCycle/100)*255;
	0CR0B = dutyCycle/100;

	sei();

	TCCR0B |= (1 << CS02);


	while (1)
	{
		
	}

}

ISR()
{
}
