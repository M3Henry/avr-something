#include "hidModule.h"
#include "lcd.h"
#include "ctrl.h"

#include <util/delay.h>

int main(void) 
{
	ctrl::disableJTAG();
	
	lcd::init();
	
	lcd::testFont();
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
