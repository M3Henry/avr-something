#pragma once
#include "utils.h"

namespace io
{
namespace pin
{
	constexpr auto& A()
	{
		return memory(0x20);
	}
	constexpr auto& B()
	{
		return memory(0x23);
	}
	constexpr auto& C()
	{
		return memory(0x26);
	}
	constexpr auto& D()
	{
		return memory(0x29);
	}
}
namespace direction
{
	constexpr auto& A()
	{
		return memory(0x21);
	}
	constexpr auto& B()
	{
		return memory(0x24);
	}
	constexpr auto& C()
	{
		return memory(0x27);
	}
	constexpr auto& D()
	{
		return memory(0x2A);
	}
}
namespace out
{
	constexpr auto& A()
	{
		return memory(0x22);
	}
	constexpr auto& B()
	{
		return memory(0x25);
	}
	constexpr auto& C()
	{
		return memory(0x28);
	}
	constexpr auto& D()
	{
		return memory(0x2B);
	}
}
}
