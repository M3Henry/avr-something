#include "hidModule.h"
#include "lcd.h"
#include "ctrl.h"

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
}

}

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
	
	uint8_t x = 0;
	uint16_t y = 0;
	for (;;)
	{
		timer::two::outputCompareA() = x++;
		
		timer::two::outputCompareB() = y-- >> 8;
		//io::pin::D() = bit(5);
		_delay_us(10);
		//io::pin::D() = bits(5, 7);
		//_delay_ms(1);
	}

}
