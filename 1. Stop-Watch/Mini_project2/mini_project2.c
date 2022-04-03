/*
 * mini_project2.c
 *
 *  Created on: Sep 15, 2021
 *      Author: Mohamed Shereef
 */
#include<avr/io.h>
#include<avr/interrupt.h>
#include<util/delay.h>

unsigned char sec=0,min=0,hour=0;

void TIMER1_Init(void)
{
	TCCR1A = (1<<FOC1A) ;
	TCCR1B = (1<<WGM12) |(1<<CS10) |(1<<CS12);
	TCNT1 = 0;
	OCR1A=1000;
	TIMSK|=(1<<OCIE1A);

	SREG |=(1<<7);
}
ISR(TIMER1_COMPA_vect)
{
	sec++;
	if(sec==60)
	{
		sec=0;
		min++;
	}
	if(min==60)
	{
		sec=0;
		min=0;
		hour++;
	}
}

void INT0_Init_reset(void)
{
	/* configure INT0 internal pull up*/
	DDRD &=~(1<<PD2);
	PORTD|=(1<<PD2);

	MCUCR |=(1<<ISC01);
	GICR |=(1<<INT0);

	SREG |=(1<<7);
}
ISR(INT0_vect)
{
	sec=0;
	min=0;
	hour=0;
}
void INT1_Init_paused(void)
{
	/* configure INT1 with external pull down */
	DDRD &=~(1<<PD3);

	MCUCR |=(1<<ISC10) |(1<<ISC11);
	GICR |=(1<<INT1);

	SREG |=(1<<7);
}
ISR(INT1_vect)
{
	TCCR1B &= ~(1<<CS10)&~(1<<CS11)&~(1<<CS12);
}

void INT2_Init_Resume(void)
{
	/* configure INT2 internal pull up*/
	DDRB &=~(1<<PB2);
	PORTB |= (1<<PB2);

	MCUCR&=~(1<<ISC2);
	GICR |=(1<<INT2);

	SREG|=(1<<7);
}
ISR(INT2_vect)
{
	TCCR1B = (1<<WGM12) |(1<<CS10) |(1<<CS12);
}
int main(void)
{
	/*making first 4 pins in port c output*/
	DDRC =0x0F;
	PORTC =0;

	/*making first 6 pins in port c output*/
	DDRA =0xFF;
	PORTA =0xFF;


	TIMER1_Init();
	INT0_Init_reset();
	INT1_Init_paused();
	INT2_Init_Resume();



	while(1)
	{
		PORTA = (1<<5);
		PORTC = sec % 10;
		_delay_ms(5);
		PORTA = (1<<4);
		PORTC = sec / 10;
		_delay_ms(5);
		PORTA = (1<<3);
		PORTC = min % 10;
		_delay_ms(3);
		PORTA = (1<<2);
		PORTC = min / 10;
		_delay_ms(5);
		PORTA = (1<<1);
		PORTC = hour % 10;
		_delay_ms(5);
		PORTA = (1<<0);
		PORTC = hour / 10;
		_delay_ms(5);

	}
}
