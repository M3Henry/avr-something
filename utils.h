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

inline constexpr uint8_t bits()
{
	return 0;
}

template <typename...Ts>
inline constexpr uint8_t bits(const uint8_t shift, Ts... others)
{
//	static_assert(8 > shift, "must be in range (0, 7)");
	return bit(shift) | bits(others...);
}

inline constexpr uint16_t wbit(const uint8_t shift)
{
//	static_assert(8 > shift, "must be in range (0, 7)");
	return uint8_t(1) << shift;
}

inline constexpr uint8_t mix(const uint8_t a, const uint8_t mask, const uint8_t b)
{
	return (a & ~mask) | (b & mask);
}
