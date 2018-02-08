#include "hidModule.h"

#include <util/delay.h>

int main(void) 
{
	hid::test();
/*
	for (;;)
	{
		io::pin::D() = bit(5);
		_delay_ms(1);
		io::pin::D() = bit(5) | bit(7);
		_delay_ms(1);
	}
*/
}
