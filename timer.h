#pragma once
#include "utils.h"


namespace timer
{
namespace one
{
auto& control()
{
	return memory<uint16_t>(0x80);
}
auto& inputCapture()
{
	return memory<uint16_t>(0x86);
}
auto& outputCompareA()
{
	return memory<uint16_t>(0x88);
}
auto& outputCompareB()
{
	return memory<uint16_t>(0x8A);
}
}

namespace two
{
auto& control()
{
	return memory<uint16_t>(0xB0);
}
auto& value()
{
	return memory(0xB2);
}
auto& outputCompareA()
{
	return memory(0xB3);
}
auto& outputCompareB()
{
	return memory(0xB4);
}
auto& interruptMask()
{
	return memory(0x70);
}
auto const& interruptFlags()
{
	return memory(0x37);
}
}

}
