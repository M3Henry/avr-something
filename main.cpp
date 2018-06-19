#include "hidModule.h"
#include "lcd.h"
#include "timer.h"
#include "ctrl.h"

#include <avr/interrupt.h>
#include <util/delay.h>



int8_t const sinTable[] [[gnu::progmem]] =
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
	hid::init();
	lcd::init();

	lcd::testFont();

	io::direction::D() |= bits(5, 6, 7);

	timer::two::outputCompareA() = 0x80;
	timer::two::outputCompareB() = 0x80;
	timer::two::control() = 0b00'00'0'001'1111'00'11;

	for (;;)
	{
	//	LEDs

		auto val = hid::sampleInput();

		const auto r = (val & (hid::buttonL | hid::wheelA)) ? hid::ledRED : 0;
		const auto y = (val & (hid::buttonD | hid::buttonU)) ? hid::ledYEL : 0;
		const auto g = (val & (hid::buttonR | hid::wheelB)) ? hid::ledGRN : 0;

		const auto leds = r | y | g;

		hid::setLeds((val & hid::buttonC) ? ~leds : leds);

	//	Sound

		constexpr uint8_t midPoint = 127;
		constexpr auto begin = flashPtr<int8_t>(sinTable);
		constexpr auto end = begin + 64;
		auto ptr = flashPtr<int8_t>(sinTable);
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
