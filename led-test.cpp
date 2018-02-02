#include "led.h"
#include "io.h"
#include <util/delay.h>

int main(void)
{
	io::direction::B() |= 0x80;
	for(;;)
	{
		blink();
		_delay_ms(333);
	}
}
