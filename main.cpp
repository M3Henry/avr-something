#include "led.h"
#include "io.h"
#include <util/delay.h>

constexpr uint8_t bit(const uint8_t shift)
{
//	static_assert(8 > shift, "must be in range (0, 7)");
	return uint8_t(1) << shift;
}

/*
	B0
	B1	SD ???
	B2	!USB!
	B3	!USB!
	B4	SD _SS_
	B5	SD MOSI
	B6	SD MISO
	B7	SD SCLK | LED red

	C2	U-B | B
	C3	D-B | C-B
	C4	R-B | A
	C5	L-B

	D0	WHEEL COM B
	D1	WHEEL COM A
	D2	RS232 RX1
	D3	RS232 TX1
	D4	LED yellow
	D5	L OC1A | ADC5
	D6	LED green
	D7	R OC2A | ADC7
*/

int main(void) 
{
	io::direction::B() = bit(7);
	io::direction::D() = bit(4) | bit(6);
	
	
	io::direction::D() = bit(5) | bit(7);
	
	
/*	for(;;)
	{
		io::pin::D() = bit(5);
		_delay_ms(1);
		io::pin::D() = bit(5) | bit(7);
		_delay_ms(1);
	}
*/	
	for(;;)
	{
		io::out::B() = bit(7);
		io::out::D() = bit(4);
		_delay_ms(300);
		io::out::B() = 0;
		io::out::D() = bit(6);
		_delay_ms(600);
	}
}
