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

inline constexpr auto& control()
{
	return io::out::A();
}
inline constexpr auto& data()
{
	return io::out::C();
}
inline constexpr auto& controlDir()
{
	return io::direction::A();
}
inline constexpr auto& dataDir()
{
	return io::direction::C();
}

constexpr uint16_t red   = 0xF800;
constexpr uint16_t green = 0x07E0;
constexpr uint16_t blue  = 0x001F;

static_assert(red + green + blue == 0xFFFF, "RGB masks sum incorrectly");

void init();

[[noreturn]]
void test();

void testFont();

}
