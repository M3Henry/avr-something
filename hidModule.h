#pragma once

#include "io.h"

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
namespace hid {

constexpr auto buttonCOM = bit(0);
constexpr auto wheelCOM = bit(1);

constexpr auto wheelA = bit(0);
constexpr auto wheelB = bit(1);
constexpr auto buttonC = bit(2);
constexpr auto buttonL = bit(3);
constexpr auto buttonU = bit(4);
constexpr auto buttonR = bit(5);
constexpr auto buttonD = bit(6);

constexpr auto ledRED = bit(7);
constexpr auto ledYEL = bit(4);
constexpr auto ledGRN = bit(5);

void init();

uint8_t sampleInput();

void setLeds(const uint8_t);

[[noreturn]]
void test();

}
