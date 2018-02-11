#include "lcd.h"
#include "hidModule.h"

#include <util/delay.h>
#include "font.h"

/*
	A0~ chip select
	A1  Backlight
	A2~ Reset
	A3~ Write
	A4~ Command
	A5~ Read
	A6~ Vsync
	A7~ Hsync

	C[0-7] DATA BUS
*/
namespace lcd {

void send(const uint8_t d)
{
	control() = defaultControl & n_write;
	data() = d;
	control() = defaultControl;
}

void send(const uint16_t d)
{
	send(uint8_t(d >> 8));
	send(uint8_t(d));
}

template <typename...Ts>
void cmd(const uint8_t c, Ts... params)
{
	control() = defaultControl & n_command & n_write;
	data() = c;
	control() = defaultControl;
	
	// https://stackoverflow.com/questions/25680461/variadic-template-pack-expansion#25683817
	// TODO:(C++17)      (send(params), ...);
	char dummy[] __attribute__((unused)) {0, (send(uint8_t(params)), '\0')...};
}

void fillScreen(uint16_t colour)
{
	cmd(0x2C);
	uint8_t j = (320ul * 240) / (256 * 2);
	uint8_t i = 0; // uses wraparound
	do
	{
		do {
			lcd::send(colour);
			lcd::send(colour);
		} while (--i);
	} while (--j);
}

void init()
{
	controlDir() = 0xFF;
	dataDir() = 0xFF;
	
	control() = defaultControl & n_reset;
	_delay_us(16);
	control() = defaultControl;
	_delay_ms(128);
	
	
	cmd(0x11); // awake
	_delay_ms(6);
	
	cmd(0x3A, 0x55); // 16 bits per pixel
	
	fillScreen(0);
	
	cmd(0x29); // display ON
}

[[noreturn]]
void test()
{
	union pixel
	{
		struct __attribute__((packed)) {
			uint8_t r:5;
			uint8_t g:6;
			uint8_t b:5;
		};
		uint16_t word;
		
		pixel() : word(0) {}
	} p;
	
	static_assert(sizeof(pixel) == sizeof(uint16_t), "not correct size");
	
	init();
	
	cmd(0x2C);
	
	for (;;)
	{
		//if (0 == ++p.r) if (0 == ++p.b) --p.g;
		
		//send(p.word);
		//send(uint16_t(0xF800));
		auto x = hid::sampleInput();
		send(x);
		send(x);
	}
}

void testFont()
{
	cmd(0x2A);
	send(uint16_t(0));
	send(uint16_t(7));
	
	cmd(0x2C);
	
	for (auto const r : mash::X)
	{
		send(r & bit(0) ? uint16_t(0xF800) : uint16_t(0x001F));
		send(r & bit(1) ? uint16_t(0xF800) : uint16_t(0x001F));
		send(r & bit(2) ? uint16_t(0xF800) : uint16_t(0x001F));
		send(r & bit(3) ? uint16_t(0xF800) : uint16_t(0x001F));
		send(r & bit(4) ? uint16_t(0xF800) : uint16_t(0x001F));
		send(r & bit(5) ? uint16_t(0xF800) : uint16_t(0x001F));
		send(r & bit(6) ? uint16_t(0xF800) : uint16_t(0x001F));
		send(r & bit(7) ? uint16_t(0xF800) : uint16_t(0x001F));
	}
}

}
