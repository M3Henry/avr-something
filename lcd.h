#pragma once

#include "io.h"
#include "hidModule.h"

#include <util/delay.h>

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

constexpr auto n_select = ~bit(0);
constexpr auto backlight = bit(1);
constexpr auto n_reset = ~bit(2);
constexpr auto n_write = ~bit(3);
constexpr auto n_command = ~bit(4);
constexpr auto n_read = ~bit(5);
constexpr auto n_vsync = ~bit(6);
constexpr auto n_hsync = ~bit(7);

constexpr auto defaultControl = n_select;

auto& control = io::out::A();
auto& data = io::out::C();
auto& controlDir = io::direction::A();
auto& dataDir = io::direction::C();

[[noreturn]] void test();

void send(const uint8_t d)
{
	control = defaultControl & n_write;
	data = d;
	control = defaultControl;
}

void send(const uint16_t d)
{
	send(uint8_t(d >> 8));
	send(uint8_t(d));
}

template <typename...Ts>
void cmd(const uint8_t c, Ts... params)
{
	control = defaultControl & n_command & n_write;
	data = c;
	control = defaultControl;
	
	// https://stackoverflow.com/questions/25680461/variadic-template-pack-expansion#25683817
	// TODO:(C++17)      send(params), ...;
	char dummy[] __attribute__((unused)) {0, (send(uint8_t(params)), '\0')...};
}

void init()
{
	controlDir = 0xFF;
	dataDir = 0xFF;
	
	control = defaultControl & n_reset;
	_delay_us(16);
	control = defaultControl;
	_delay_ms(128);
	
	
	cmd(0x11); // awake
	_delay_ms(6);
	
	cmd(0x3A, 0x55); // 16 bits per pixel
	
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

}
