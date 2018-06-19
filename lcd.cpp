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
	
	cmd(0x36, 0x20); // x/y -> y/x
	
	cmd(0x29); // display ON
}

union colour
{
	struct __attribute__((packed)) {
		uint8_t r:5;
		uint8_t g:6;
		uint8_t b:5;
	};
	uint16_t word;
	
	constexpr colour(uint16_t const val = 0)
	:	word(val)
	{}
	
	constexpr colour(uint8_t const red, uint8_t const green, uint8_t const blue)
	:	r(red)
	,	g(green)
	,	b(blue)
	{}
	constexpr operator uint16_t() const
	{
		return word;
	}
	static constexpr auto grey(uint8_t val)
	{
		return colour(val >> 1, val, val >> 1);
	}
} p;

static_assert(sizeof(colour) == sizeof(uint16_t), "not correct size");

[[noreturn]]
void test()
{

	
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
		switch (c)
		{
			case '\n':
				newline();
				return;
			case '\f':
				y = 0;
				// fallthrough
			case '\r':
				cr();
				return;
			case 0x7F:
				x -= 8;
				putc(' ');
				x -= 8;
				return;
		}
		
		setColumns(x, x + 7);
		setRows(y, y + 7);
		advance();
		
		auto g = drawSequence();
		
		auto bytePtr = flashPtr<uint8_t>(fonts::mash[c - ' ']);
		
		uint8_t x = 8;
		do
		{
			auto byte = bytePtr.load_post_inc();
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
	void newline()
	{
		y += 8;
		cr();
	}
	void cr()
	{
		x = 0;
	}
	void advance(uint8_t count = 1)
	{
		if (x >= 320 - 8) newline();
		else x += count * 8;
	}
	void puts_ram(char const* str)
	{
		while (auto c = *str++) putc(c);
	}
	void puts(flashPtr<char> str)
	{
		while (auto c = str.load_post_inc()) putc(c);
	}
	void putu(uint16_t val)
	{
		if (val >= 10)
		{
			putu(val / 10);
			putc(val % 10 + '0');
		}
		else
		{
			putc(val + '0');
		}
	}
	void puti(int16_t val)
	{
		if (val < 0)
		{
			putc('-');
			putu(-val); // does not handle min(int16_t)
			return;
		}
		putu(val);
	}

	uint16_t x = 0, y = 0;
	uint16_t foreground = white;
	uint16_t background = dgrey;
	fonts::glyph const* glyphs = fonts::mash;
} lout;

char const testStr[] [[gnu::__progmem__]] = "\n\nHello, World!\nIt is a very nice day today, what are you up to this afternoon?\n";

char const clearNum[] [[gnu::__progmem__]] = "\r      \r";

void testFont()
{
	lout.foreground = green;
	for (char c = ' '; c < 0x7F;)
	{
		lout.putc(c);
		if (not (++c % 0x10)) lout.newline();
	}
	lout.background = black;
	lout.foreground = colour(0xF,0x0,0xF);
	
	lout.puts(testStr);
	lout.putu(5);
	lout.newline();
	lout.newline();
	return;
	lout.foreground = white;
	int16_t x = -32000;
	for (;;)
	{
		lout.puti(x);
		x += 10;
		_delay_ms(50);
		lout.puts(clearNum);
	}
}

}
