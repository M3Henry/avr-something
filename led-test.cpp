#include "led.h"
#include "io.h"
#include <util/delay.h>

int main(void)
{
	io::direction::B() = 0xFF;

	// OCR0A
	auto& val = memory(0x47);

	// TCCR0B
	memory(0x45) = 0x05;
	// TCCR0A
	memory(0x44) = 0xC3;


	uint8_t i = 0x00;
	for (;;)
	{
		do
		{
			i <<= 1;
			i |= 1;
			val = i;
			_delay_ms(500);
		} while (0xFF != i);
		do
		{
			i >>= 1;
			val = i;
			_delay_ms(500);
		} while (i);
	}
}
