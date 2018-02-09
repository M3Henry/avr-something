#include "hidModule.h"
#include "ctrl.h"

void hid::test()
{
	ctrl::disableJTAG();
	
	io::direction::B() = ledRED;
	
	io::direction::C() = 0;
	io::out::C() = 0xFF;
	
	uint8_t stateD = 0;
	io::out::D() = buttonCOM;
	io::direction::D() = buttonCOM | wheelCOM | ledYEL | ledGRN;
	
	for (;;)
	{
		auto val = ~io::pin::C();
		io::out::D() = wheelCOM | stateD;
		auto r = (val << 3) & ledRED;
		auto a = (val << 2) & ledYEL;
		auto b = (val << 3) & ledGRN;
		
		io::out::B() = r;
		io::out::D() = wheelCOM | (stateD = a | b);
		
		auto butts = ~io::pin::C();
		io::out::D() = buttonCOM | stateD;
		
		if (butts & buttonD) butts = 0xFF;
		auto x = (butts << 3) & ledRED;
		auto y = (butts << 2) & ledYEL;
		auto z = (butts << 3) & ledGRN;
		
		io::out::B() = x;
		io::out::D() = buttonCOM | (stateD = y | z);
	}
}
