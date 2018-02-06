#include "io.h"
#include "ctrl.h"

#include <util/delay.h>

/*
10		GND
	9	C5
8		
	7	AREF
6		_RESET_
	5	C3
4		AVCC
	3	C4
2		GND
	1	C2
	
	
	B0
	B1	SD ???
	B2	!USB!
	B3	!USB!
	B4	SD _SS_
	B5	SD MOSI
	B6	SD MISO
	B7	SD SCLK | LED red

	C2	U-B~ | W-A
	C3	D-B~ | W-B
	C4	R-B~ | C-B~
	C5	L-B~

	D0	BUTTON COM B
	D1	WHEEL COM A
	D2	RS232 RX1
	D3	RS232 TX1
	D4	LED yellow
	D5	L OC1A | ADC5
	D6	LED green
	D7	R OC2A | ADC7
*/
constexpr auto wheelCOM = bit(1);
constexpr auto wheelA = bit(2);
constexpr auto wheelB = bit(3);

constexpr auto ledRED = bit(7);
constexpr auto ledYEL = bit(4);
constexpr auto ledGRN = bit(6);

int main(void) 
{
	ctrl::disableJTAG();
	
	io::out::C() = wheelA | wheelB;
	io::direction::C() = 0;
	
	io::out::D() = 0;
	io::direction::D() = wheelCOM | ledYEL | ledGRN;
	
	for (;;)
	{
		auto val = io::pin::C();
		auto a = (val & wheelA) << 2;
		auto b = (val & wheelB) << 3;
		
		io::out::D() = a | b;
	}

/*
	for (;;)
	{
		io::pin::D() = bit(5);
		_delay_ms(1);
		io::pin::D() = bit(5) | bit(7);
		_delay_ms(1);
	}

	for (;;)
	{
		io::out::B() = bit(7);
		io::out::D() = bit(4);
		_delay_ms(300);
		io::out::B() = 0;
		io::out::D() = bit(6);
		_delay_ms(600);
	}
*/
}
