/*
 * Microcontrollers_Opdrachten.c
 *
 * Created: 30-1-2019 11:02:15
 * Author : Dion van der Linden
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include "globals.h"
#include "track1.h"
#include "track2.h"

// Main entry point.
int main(void)
{
    //DDRD = 0b11111111;			// All pins PORTD are set to output 
	//DDRC = 0x00;
    run_track2();

	return 0;
}

