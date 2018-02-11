#include "hidModule.h"
#include "ctrl.h"
#include <util/delay.h>

void hid::init()
{
	io::direction::B() = ledRED;
	
	io::out::D() = wheelCOM | buttonCOM;
	io::direction::D() = wheelCOM | buttonCOM | ledYEL | ledGRN;
}

uint8_t hid::sampleInput()
{
	constexpr uint8_t maskC = 0b00111100;
	constexpr uint8_t maskD = wheelCOM | buttonCOM;
	
	const auto saveCdir = io::direction::C();
	io::direction::C() = saveCdir & ~maskC;
	
	const auto saveCout = io::out::C();
	io::out::C() = saveCout | maskC;
	io::out::D() = mix(io::out::D(), maskD, wheelCOM);

	_delay_us(1);
	auto buttons = (maskC & ~io::pin::C()) << 1;
	io::pin::D() = maskD;
	
	_delay_us(1);
	buttons |= (maskC & ~io::pin::C()) >> 2;
	
	io::out::C() = saveCout;
	io::direction::C() = saveCdir;
	
	return buttons;
}

void hid::setLeds(const uint8_t val)
{
	io::out::B() = mix(io::out::B(), ledRED, val);
	io::out::D() = mix(io::out::D(), ledYEL | ledGRN, val);
}

void hid::test()
{
	ctrl::disableJTAG();
	
	init();
	
	for (;;)
	{
		auto val = sampleInput();
		
		const auto r = (val & (buttonL | wheelA)) ? ledRED : 0;
		const auto y = (val & (buttonD | buttonU)) ? ledYEL : 0;
		const auto g = (val & (buttonR | wheelB)) ? ledGRN : 0;
		
		const auto leds = r | y | g;
		
		setLeds((val & buttonC) ? ~leds : leds);
	}
}
