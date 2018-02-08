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

	C2	U-B | W-A
	C3	D-B | W-B
	C4	R-B | C-B
	C5	L-B

	D0	BUTTON COM B
	D1	WHEEL COM A
	D2	RS232 RX1
	D3	RS232 TX1
	D4	LED yellow
	D5	L OC1A | ADC5
	D6	LED green
	D7	R OC2A | ADC7
*/
constexpr auto buttonCOM = bit(0);
constexpr auto buttonL = bit(2);
constexpr auto buttonU = bit(3);
constexpr auto buttonR = bit(4);
constexpr auto buttonD = bit(5);

constexpr auto wheelCOM = bit(1);
constexpr auto wheelA = bit(2);
constexpr auto wheelB = bit(3);
constexpr auto buttonC = bit(4);

constexpr auto ledRED = bit(7);
constexpr auto ledYEL = bit(4);
constexpr auto ledGRN = bit(6);

int main(void) 
{
	ctrl::disableJTAG();
	
	io::direction::B() = ledRED;
	
	io::direction::C() = 0;
	io::out::C() = 0xFF;
	
	uint8_t stateD = 0;
	io::out::D() = buttonCOM;
	io::direction::D() = buttonCOM | wheelCOM | ledYEL | ledGRN;
	
	for (;;)
	{
		auto val = ~io::pin::C();
		io::out::D() = wheelCOM | stateD;
		auto r = (val << 3) & ledRED;
		auto a = (val << 2) & ledYEL;
		auto b = (val << 3) & ledGRN;
		
		io::out::B() = r;
		io::out::D() = wheelCOM | (stateD = a | b);
		
		auto butts = ~io::pin::C();
		io::out::D() = buttonCOM | stateD;
		
		if (butts & buttonD) butts = 0xFF;
		auto x = (butts << 3) & ledRED;
		auto y = (butts << 2) & ledYEL;
		auto z = (butts << 3) & ledGRN;
		
		io::out::B() = x;
		io::out::D() = buttonCOM | (stateD = y | z);
	}

/*
	for (;;)
	{
		io::pin::D() = bit(5);
		_delay_ms(1);
		io::pin::D() = bit(5) | bit(7);
		_delay_ms(1);
	}
*/
}
