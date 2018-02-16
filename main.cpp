#include "hidModule.h"
#include "lcd.h"
#include "ctrl.h"

#include <avr/interrupt.h>
#include <util/delay.h>

namespace timer
{
namespace one
{
auto& control()
{
	return memory<uint16_t>(0x80);
}
auto& inputCapture()
{
	return memory<uint16_t>(0x86);
}
auto& outputCompareA()
{
	return memory<uint16_t>(0x88);
}
auto& outputCompareB()
{
	return memory<uint16_t>(0x8A);
}
}

namespace two
{
auto& control()
{
	return memory<uint16_t>(0xB0);
}
auto& value()
{
	return memory(0xB2);
}
auto& outputCompareA()
{
	return memory(0xB3);
}
auto& outputCompareB()
{
	return memory(0xB4);
}
auto& interruptMask()
{
	return memory(0x70);
}
auto const& interruptFlags()
{
	return memory(0x37);
}
}

}

uint8_t const sinTable[] [[gnu::progmem]] =
{
	0,	3,	6,	9,	12,	16,	19,	22,
	25,	28,	31,	34,	37,	40,	43,	46,
	49,	51,	54,	57,	60,	63,	65,	68,
	71,	73,	76,	78,	81,	83,	85,	88,
	90,	92,	94,	96,	98,	100,102,104,
	106,107,109,111,112,113,115,116,
	117,118,120,121,122,122,123,124,
	125,125,126,126,126,127,127,127
};

int main(void) 
{
	ctrl::disableJTAG();
	
	lcd::init();
	
	lcd::testFont();
	
	io::direction::D() |= bits(5, 6, 7);
	
	/*timer::one::outputCompareA() = 0x0080;
	timer::one::outputCompareB() = 0x8000;
	timer::one::inputCapture() = 0x0100;
	timer::one::control() = 0b00'0'10'001'1111'00'00;*/
	
	timer::two::outputCompareA() = 0x80;
	timer::two::outputCompareB() = 0x80;
	timer::two::control() = 0b00'00'0'001'1111'00'11;

	for (;;)
	{
		constexpr uint8_t midPoint = 127;
		constexpr auto begin = flashPtr(sinTable);
		constexpr auto end = begin + 64;
		auto ptr = flashPtr(sinTable);
		do
		{
			auto val = midPoint + ptr.load_post_inc();
			timer::two::outputCompareA() = val;
			timer::two::outputCompareB() = val;
			_delay_us(10);
		}
		while (ptr != end);

		while (ptr != begin)
		{
			auto val = midPoint + (--ptr).load();
			timer::two::outputCompareA() = val;
			timer::two::outputCompareB() = val;
			_delay_us(10);
		}

		do
		{
			auto val = midPoint - ptr.load_post_inc();
			timer::two::outputCompareA() = val;
			timer::two::outputCompareB() = val;
			_delay_us(10);
		}
		while (ptr != end);

		while (ptr != begin)
		{
			auto val = midPoint - (--ptr).load();
			timer::two::outputCompareA() = val;
			timer::two::outputCompareB() = val;
			_delay_us(10);
		}
	}

}
