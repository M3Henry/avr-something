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
	char dummy[] {0, (send(uint8_t(params)), '\0')...};
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
	
	cmd(0x36, 0x20); // x/y -> y/x
	
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

void setColumns(const uint16_t start, const uint16_t end)
{
	cmd(0x2A);
	send(start);
	send(end);
}

void setRows(const uint16_t start, const uint16_t end)
{
	cmd(0x2B);
	send(start);
	send(end);
}

struct drawSequence
{
	drawSequence()
	{
		cmd(0x2C);
	}
	~drawSequence()
	{
		cmd(0);
	}
};

struct
{
	void putc(const char c)
	{
		setColumns(y, y + 7);
		y += 8;
		setRows(0, 7);
		
		auto g = drawSequence();
		
		uint8_t const* bytePtr = fonts::mash[c - ' '];
		
		uint8_t x = 8;
		do
		{
			auto byte = pgm_read_byte(bytePtr++);
			send(byte & bit(7) ? foreground : background);
			send(byte & bit(6) ? foreground : background);
			send(byte & bit(5) ? foreground : background);
			send(byte & bit(4) ? foreground : background);
			send(byte & bit(3) ? foreground : background);
			send(byte & bit(2) ? foreground : background);
			send(byte & bit(1) ? foreground : background);
			send(byte & bit(0) ? foreground : background);
		}
		while (--x);
	}
	void puts(char const* str)
	{
		while (auto c = *str++) putc(c);
	}

	uint16_t x = 0, y = 0;
	uint16_t foreground = white;
	uint16_t background = dgrey;
	fonts::glyph const* glyphs = fonts::mash;
} lout;

void testFont()
{
	lout.puts("Hello, World!");
}

}
