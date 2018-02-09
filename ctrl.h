#pragma once
#include "utils.h"

namespace ctrl
{
extern volatile uint8_t& mcu;

inline void disableJTAG()
{
	auto tmp = mcu | bit(7);
	mcu = tmp;
	mcu = tmp;
}

}
