#include "led.h"
#include "io.h"
#include <util/delay.h>

constexpr uint8_t bit(const uint8_t shift)
{
//	static_assert(8 > shift, "must be in range (0, 7)");
	return uint8_t(1) << shift;
}

namespace lcd
{
	auto& control()
	{
		return io::pin::A();
	}
	auto& data()
	{
		return io::pin::C();
	}
	
	namespace signal
	{
		constexpr auto select_n = bit(0);
		constexpr auto backlight = bit(1);
		constexpr auto reset_n = bit(2);
		constexpr auto write_n = bit(3);
		constexpr auto command_n = bit(4);
		constexpr auto read_n = bit(5);
		constexpr auto vSync = bit(6);
		constexpr auto hSync = bit(7);
	}
	
	void init()
	{
		control() = 0b11111001;
		io::direction::A() = 0xFF;
		io::direction::C() = 0xFF;
		
//	FMARK	VSYNC	!READ		DATA/!CTRL	!WRITE	!RESET	BACKLI	!CHIPSELECT
		
		_delay_ms(16);
		control() = 0xFF;
	}
	void writeCommand(const uint8_t cmd)
	{
		// control sequence probably wrong!
		
		using namespace signal;
		control() = ~command_n;
		data() = cmd;
		control() = ~(command_n | write_n);
		control() = 0xFF;
	}
}

int main(void) 
{
	auto& mcuCtrl = memory(0x55);
	mcuCtrl |= 0x80;
	mcuCtrl |= 0x80;
	
	lcd::init();
	
	for(;;);
}
