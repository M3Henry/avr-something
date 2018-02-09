#pragma once
#include <inttypes.h>

template <typename T = uint8_t>
constexpr T volatile& memory(const uintptr_t addr)
{
	return *reinterpret_cast<T*>(addr);
}

inline constexpr uint8_t bit(const uint8_t shift)
{
//	static_assert(8 > shift, "must be in range (0, 7)");
	return uint8_t(1) << shift;
}

inline constexpr uint16_t wbit(const uint8_t shift)
{
//	static_assert(8 > shift, "must be in range (0, 7)");
	return uint8_t(1) << shift;
}
