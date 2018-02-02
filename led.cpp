#include "led.h"
#include "io.h"

void blink(void)
{
	io::pin::B() |= 0x80;
}
