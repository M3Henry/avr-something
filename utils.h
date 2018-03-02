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

template <typename T>
struct flashPtr
{
	static_assert(sizeof(T) == 1, "flashPtr operates on single bytes");
	
	constexpr flashPtr(T const* const p)
	:	ptr(p)
	{}
	template <uint16_t S>
	constexpr flashPtr(const T(& a)[S])
	:	ptr(static_cast<T const*>(a))
	{}
	
	T load() const
	{
		T result;
		asm volatile
		(
			"lpm %0, Z"

			: "=r" (result)
			: "z" (ptr)
		);
		return result;
	}
	T load_post_inc()
	{
		T result;
		asm volatile
		(
			"lpm %0, Z+"

			: "=r" (result), "=z" (ptr)
			: "1" (ptr)
		);
		return result;
	}
	constexpr flashPtr& operator ++()
	{
		++ptr;
		return *this;
	}
	constexpr flashPtr& operator --()
	{
		--ptr;
		return *this;
	}
	constexpr flashPtr operator +(const uint16_t delta) const
	{
		return flashPtr(ptr + delta);
	}
	constexpr flashPtr operator -(const uint16_t delta) const
	{
		return flashPtr(ptr - delta);
	}
	constexpr bool operator !=(const flashPtr& that) const
	{
		return ptr != that.ptr;
	}

	static_assert(sizeof(uint16_t) == sizeof(T const *), "Flash ptr should be a word");

private:
	T const* ptr;
};


