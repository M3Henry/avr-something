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

inline constexpr uint8_t mix(const uint8_t a, const uint8_t b, const uint8_t mask)
{
	return (a & ~mask) | (b & mask);
}

struct flashPtr
{
	inline constexpr flashPtr(uint8_t const* const p) : ptr(p) {}
	inline uint8_t load() const
	{
		uint8_t result;
		asm volatile
		(
			"lpm %0, Z"

			: "=r" (result)
			: "z" (ptr)
		);
		return result;
	}
	inline uint8_t load_post_inc()
	{
		uint8_t result;
		asm volatile
		(
			"lpm %0, Z+"

			: "=r" (result), "=z" (ptr)
			: "1" (ptr)
		);
		return result;
	}
	inline constexpr flashPtr& operator ++()
	{
		++ptr;
		return *this;
	}
	inline constexpr flashPtr& operator --()
	{
		--ptr;
		return *this;
	}
	inline constexpr flashPtr operator +(const uint16_t delta) const
	{
		return flashPtr(ptr + delta);
	}
	inline constexpr flashPtr operator -(const uint16_t delta) const
	{
		return flashPtr(ptr - delta);
	}
	inline constexpr bool operator !=(const flashPtr& that) const
	{
		return ptr != that.ptr;
	}

	static_assert(sizeof(uint16_t) == sizeof(uint8_t const *), "Flash ptr should be a word");

private:
	uint8_t const* ptr;
};


