
/*
 * SecuritySystem.c
 *
 * Created: 13-3-2019 11:03:19
 * Author : Dion van der Linden
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include "../header/utils.h"
#include "../header/lcd.h"

#define PULSE_OUT 0
#define PULSE_IN 1
// Pulse out = 0
// Pulse in = 1
void write(int val);

volatile int pulse = 0;

ISR(INT0_vect)
{
	static int i = 0;
	if (i == 1)
	{
		TCCR1B = 0;
		pulse = TCNT1;
		TCNT1 = 0;
		i = 0;
	}
	if (i == 0)
	{
		TCCR1B |= 1 << CS10;
		i = 1;
	}
}

int main(void)
{
	// 0 = input 1 = output
	DDRA = 0b00000101;//0x65; // 0b00000101
    /* Replace with your application code */
	
	//EICRA |= 0b00000011;
	//EIMSK |= 0b00000001;
	
	//sei();
	
	LCD_Init();
    while (1) 
    {
		write(1);
		Utils_Wait(15);
		write(0);

		/*pulse = PORTA1;
		int count = pulse / 58;
		LCD_ClearDisplay();
		LCD_SetCursorPos(0x00);
		
		char str[8];
		itoa(count, str, 8);
		LCD_WriteString(str);*/
		Utils_Wait(1000);
		//Utils_Wait(10);
    }

	return 0;
}

void write(int toggle)
{
	if (toggle == 1)
		PORTA |= (1<<PULSE_OUT);
	else if (toggle == 0)
		PORTA &= ~(1<<PULSE_OUT);
}

