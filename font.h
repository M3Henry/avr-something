#pragma once
#include <inttypes.h>
#include <avr/pgmspace.h>

namespace fonts
{
using glyph = uint8_t[8];

using font = glyph[];

font const mash [[gnu::__progmem__]] =
{
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},//	space
	{0x18, 0x3C, 0x3C, 0x18, 0x18, 0x00, 0x18, 0x00},//	!
	{0x36, 0x36, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},//	"
	{0x14, 0x14, 0x3E, 0x14, 0x3E, 0x14, 0x14, 0x00},//	#
	{0x1C, 0x36, 0x30, 0x7C, 0x30, 0x30, 0x7E, 0x00},//	$
	{0x66, 0x64, 0x0C, 0x08, 0x18, 0x13, 0x33, 0x00},//	%
	{0x38, 0x6C, 0x6C, 0x39, 0x6E, 0x6E, 0x3B, 0x00},//	&
	{0x18, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},//	'
	{0x0C, 0x1C, 0x18, 0x18, 0x18, 0x1C, 0x0C, 0x00},//	(
	{0x18, 0x1C, 0x0C, 0x0C, 0x0C, 0x1C, 0x18, 0x00},//	)
	{0x08, 0x2A, 0x1C, 0x14, 0x22, 0x00, 0x00, 0x00},//	*
	{0x00, 0x08, 0x08, 0x3E, 0x08, 0x08, 0x00, 0x00},//	+
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x18, 0x30},//	,
	{0x00, 0x00, 0x00, 0x3E, 0x00, 0x00, 0x00, 0x00},//	-
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x18, 0x00},//	.
	{0x0C, 0x0C, 0x1C, 0x18, 0x38, 0x30, 0x30, 0x00},//	/
	{0x18, 0x24, 0x6E, 0x76, 0x66, 0x24, 0x18, 0x00},//	0
	{0x18, 0x38, 0x18, 0x18, 0x18, 0x18, 0x3C, 0x00},//	1
	{0x3C, 0x66, 0x06, 0x0C, 0x18, 0x30, 0x7E, 0x00},//	2
	{0x3C, 0x66, 0x06, 0x1C, 0x06, 0x66, 0x3C, 0x00},//	3
	{0x0E, 0x1E, 0x36, 0x66, 0x7F, 0x06, 0x06, 0x00},//	4
	{0x7E, 0x60, 0x60, 0x7C, 0x06, 0x66, 0x3C, 0x00},//	5
	{0x3C, 0x60, 0x60, 0x7C, 0x66, 0x66, 0x3C, 0x00},//	6
	{0x7E, 0x06, 0x0E, 0x0C, 0x0C, 0x18, 0x18, 0x00},//	7
	{0x3C, 0x66, 0x66, 0x3C, 0x66, 0x66, 0x3C, 0x00},//	8
	{0x3C, 0x66, 0x66, 0x3E, 0x06, 0x06, 0x06, 0x00},//	9
	{0x00, 0x00, 0x18, 0x18, 0x00, 0x18, 0x18, 0x00},//	:
	{0x00, 0x00, 0x18, 0x18, 0x00, 0x18, 0x18, 0x30},//	;
	{0x00, 0x06, 0x1C, 0x30, 0x1C, 0x06, 0x00, 0x00},//	<
	{0x00, 0x00, 0x3E, 0x00, 0x3E, 0x00, 0x00, 0x00},//	=
	{0x00, 0x30, 0x1C, 0x06, 0x1C, 0x30, 0x00, 0x00},//	>
	{0x3C, 0x66, 0x0C, 0x18, 0x00, 0x18, 0x18, 0x00},//	?
	{0x1C, 0x22, 0x4D, 0x55, 0x4E, 0x20, 0x1E, 0x00},//	@
	{0x1C, 0x3E, 0x36, 0x36, 0x7F, 0x63, 0x63, 0x00},//	A
	{0x7C, 0x66, 0x66, 0x7C, 0x66, 0x66, 0x7C, 0x00},//	B
	{0x3C, 0x66, 0x60, 0x60, 0x60, 0x66, 0x3C, 0x00},//	C
	{0x7C, 0x66, 0x66, 0x66, 0x66, 0x66, 0x7C, 0x00},//	D
	{0x7E, 0x60, 0x60, 0x7C, 0x60, 0x60, 0x7E, 0x00},//	E
	{0x7E, 0x60, 0x60, 0x7C, 0x60, 0x60, 0x60, 0x00},//	F
	{0x3C, 0x66, 0x60, 0x60, 0x6E, 0x66, 0x3C, 0x00},//	G
	{0x66, 0x66, 0x66, 0x7E, 0x66, 0x66, 0x66, 0x00},//	H
	{0x3C, 0x18, 0x18, 0x18, 0x18, 0x18, 0x3C, 0x00},//	I
	{0x1E, 0x0C, 0x0C, 0x0C, 0x0C, 0x6C, 0x38, 0x00},//	J
	{0x66, 0x6C, 0x78, 0x70, 0x78, 0x6C, 0x66, 0x00},//	K
	{0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x7E, 0x00},//	L
	{0x63, 0x77, 0x7F, 0x6B, 0x63, 0x63, 0x63, 0x00},//	M
	{0x66, 0x76, 0x7E, 0x7E, 0x6E, 0x66, 0x66, 0x00},//	N
	{0x3C, 0x66, 0x66, 0x66, 0x66, 0x66, 0x3C, 0x00},//	O
	{0x7C, 0x66, 0x66, 0x7C, 0x60, 0x60, 0x60, 0x00},//	P
	{0x3C, 0x66, 0x66, 0x66, 0x66, 0x6E, 0x3C, 0x06},//	Q
	{0x7C, 0x66, 0x66, 0x7C, 0x78, 0x6C, 0x66, 0x00},//	R
	{0x3C, 0x66, 0x70, 0x3C, 0x0E, 0x66, 0x3C, 0x00},//	S
	{0x7E, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x00},//	T
	{0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x3C, 0x00},//	U
	{0x63, 0x63, 0x36, 0x36, 0x1C, 0x1C, 0x08, 0x00},//	V
	{0x63, 0x63, 0x63, 0x6B, 0x6B, 0x36, 0x36, 0x00},//	W
	{0x66, 0x66, 0x3C, 0x18, 0x3C, 0x66, 0x66, 0x00},//	X
	{0x66, 0x66, 0x66, 0x3C, 0x18, 0x18, 0x18, 0x00},//	Y
	{0x7E, 0x06, 0x0C, 0x18, 0x30, 0x60, 0x7E, 0x00},//	Z
	{0x3C, 0x30, 0x30, 0x30, 0x30, 0x30, 0x3C, 0x00},//	[
	{0x30, 0x30, 0x38, 0x18, 0x1C, 0x0C, 0x0C, 0x00},//	'\'
	{0x3C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x3C, 0x00},//	]
	{0x08, 0x14, 0x22, 0x00, 0x00, 0x00, 0x00, 0x00},//	^
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3E, 0x00},//	_
	{0x0C, 0x06, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00},//	`
	{0x00, 0x00, 0x1E, 0x36, 0x36, 0x36, 0x1F, 0x00},//	a
	{0x30, 0x30, 0x3C, 0x36, 0x36, 0x36, 0x3C, 0x00},//	b
	{0x00, 0x00, 0x1C, 0x36, 0x30, 0x36, 0x1C, 0x00},//	c
	{0x06, 0x06, 0x1E, 0x36, 0x36, 0x36, 0x1F, 0x00},//	d
	{0x00, 0x00, 0x1C, 0x36, 0x3C, 0x30, 0x1C, 0x00},//	e
	{0x0E, 0x18, 0x18, 0x18, 0x3C, 0x18, 0x18, 0x00},//	f
	{0x00, 0x00, 0x1E, 0x36, 0x36, 0x1E, 0x06, 0x1C},//	g
	{0x30, 0x30, 0x3C, 0x36, 0x36, 0x36, 0x36, 0x00},//	h
	{0x00, 0x18, 0x00, 0x18, 0x18, 0x18, 0x18, 0x00},//	i
	{0x00, 0x0C, 0x00, 0x0C, 0x0C, 0x0C, 0x2C, 0x18},//	j
	{0x30, 0x30, 0x36, 0x3C, 0x3C, 0x36, 0x36, 0x00},//	k
	{0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x0C, 0x00},//	l
	{0x00, 0x00, 0x76, 0x6B, 0x6B, 0x6B, 0x63, 0x00},//	m
	{0x00, 0x00, 0x3C, 0x36, 0x36, 0x36, 0x36, 0x00},//	n
	{0x00, 0x00, 0x1C, 0x36, 0x36, 0x36, 0x1C, 0x00},//	o
	{0x00, 0x00, 0x3C, 0x36, 0x36, 0x36, 0x3C, 0x30},//	p
	{0x00, 0x00, 0x1E, 0x36, 0x36, 0x36, 0x1E, 0x06},//	q
	{0x00, 0x00, 0x3C, 0x32, 0x30, 0x30, 0x30, 0x00},//	r
	{0x00, 0x00, 0x1E, 0x30, 0x1C, 0x06, 0x3C, 0x00},//	s
	{0x00, 0x18, 0x3C, 0x18, 0x18, 0x18, 0x0C, 0x00},//	t
	{0x00, 0x00, 0x36, 0x36, 0x36, 0x36, 0x1C, 0x00},//	u
	{0x00, 0x00, 0x36, 0x36, 0x36, 0x1C, 0x08, 0x00},//	v
	{0x00, 0x00, 0x63, 0x6B, 0x6B, 0x3E, 0x14, 0x00},//	w
	{0x00, 0x00, 0x36, 0x1C, 0x08, 0x1C, 0x36, 0x00},//	x
	{0x00, 0x00, 0x36, 0x36, 0x36, 0x1E, 0x06, 0x1C},//	y
	{0x00, 0x00, 0x3E, 0x0C, 0x18, 0x30, 0x3E, 0x00},//	z
	{0x0C, 0x08, 0x18, 0x30, 0x18, 0x08, 0x0C, 0x00},//	{
	{0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x00},//	|
	{0x18, 0x08, 0x0C, 0x06, 0x0C, 0x08, 0x18, 0x00},//	}
	{0x00, 0x00, 0x30, 0x49, 0x06, 0x00, 0x00, 0x00}//	~
};

font const oryxB [[gnu::__progmem__]] =
{
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},//	space
	{0x00, 0x18, 0x18, 0x18, 0x08, 0x00, 0x18, 0x00},//	!
	{0x36, 0x36, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},//	"
	{0x00, 0x36, 0x7F, 0x36, 0x36, 0x7F, 0x36, 0x00},//	#
	{0x1C, 0x36, 0x30, 0x7C, 0x30, 0x30, 0x7E, 0x00},//	$
	{0x66, 0x64, 0x0C, 0x08, 0x18, 0x13, 0x33, 0x00},//	%
	{0x38, 0x6C, 0x6C, 0x39, 0x6E, 0x6E, 0x3B, 0x00},//	&
	{0x18, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},//	'
	{0x0C, 0x1C, 0x18, 0x18, 0x18, 0x1C, 0x0C, 0x00},//	(
	{0x18, 0x1C, 0x0C, 0x0C, 0x0C, 0x1C, 0x18, 0x00},//	)
	{0x08, 0x2A, 0x1C, 0x14, 0x22, 0x00, 0x00, 0x00},//	*
	{0x00, 0x08, 0x08, 0x3E, 0x08, 0x08, 0x00, 0x00},//	+
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x18, 0x30},//	,
	{0x00, 0x00, 0x00, 0x3E, 0x00, 0x00, 0x00, 0x00},//	-
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x18, 0x00},//	.
	{0x0C, 0x0C, 0x1C, 0x18, 0x38, 0x30, 0x30, 0x00},//	/
	{0x00, 0x3C, 0x66, 0x76, 0x6E, 0x66, 0x3C, 0x00},//	0
	{0x00, 0x18, 0x38, 0x18, 0x18, 0x18, 0x3C, 0x00},//	1
	{0x00, 0x3C, 0x66, 0x0E, 0x3C, 0x70, 0x7E, 0x00},//	2
	{0x00, 0x3C, 0x66, 0x1C, 0x06, 0x66, 0x3C, 0x00},//	3
	{0x00, 0x1C, 0x2C, 0x4C, 0x4C, 0x7E, 0x0C, 0x00},//	4
	{0x00, 0x7C, 0x60, 0x7C, 0x06, 0x66, 0x3C, 0x00},//	5
	{0x00, 0x3C, 0x60, 0x7C, 0x66, 0x66, 0x3C, 0x00},//	6
	{0x00, 0x7E, 0x06, 0x0C, 0x18, 0x18, 0x18, 0x00},//	7
	{0x00, 0x3C, 0x66, 0x3C, 0x66, 0x66, 0x3C, 0x00},//	8
	{0x00, 0x3C, 0x66, 0x66, 0x3E, 0x06, 0x3C, 0x00},//	9
	{0x00, 0x00, 0x18, 0x18, 0x00, 0x18, 0x18, 0x00},//	:
	{0x00, 0x00, 0x18, 0x18, 0x00, 0x18, 0x18, 0x30},//	;
	{0x00, 0x06, 0x1C, 0x30, 0x1C, 0x06, 0x00, 0x00},//	<
	{0x00, 0x00, 0x3E, 0x00, 0x3E, 0x00, 0x00, 0x00},//	=
	{0x00, 0x30, 0x1C, 0x06, 0x1C, 0x30, 0x00, 0x00},//	>
	{0x00, 0x7C, 0xCE, 0xCE, 0x18, 0x00, 0x18, 0x00},//	?
	{0x1C, 0x22, 0x4D, 0x55, 0x4E, 0x20, 0x1E, 0x00},//	@
	{0x00, 0x38, 0x7C, 0xE6, 0xFE, 0xE6, 0xE6, 0x00},//	A
	{0x00, 0xFC, 0xE6, 0xFC, 0xE6, 0xE6, 0xFC, 0x00},//	B
	{0x00, 0x7C, 0xE6, 0xE0, 0xE0, 0xE6, 0x7C, 0x00},//	C
	{0x00, 0xFC, 0xE6, 0xE6, 0xE6, 0xE6, 0xFC, 0x00},//	D
	{0x00, 0xFE, 0xE0, 0xFC, 0xE0, 0xE0, 0xFE, 0x00},//	E
	{0x00, 0xFE, 0xE0, 0xFC, 0xE0, 0xE0, 0xE0, 0x00},//	F
	{0x00, 0x7C, 0xE6, 0xE0, 0xEE, 0xE6, 0x7C, 0x00},//	G
	{0x00, 0xE6, 0xE6, 0xFE, 0xE6, 0xE6, 0xE6, 0x00},//	H
	{0x00, 0x7C, 0x38, 0x38, 0x38, 0x38, 0x7C, 0x00},//	I
	{0x00, 0xFE, 0x1C, 0x1C, 0xDC, 0xDC, 0x78, 0x00},//	J
	{0x00, 0xE6, 0xEC, 0xF8, 0xF8, 0xEC, 0xE6, 0x00},//	K
	{0x00, 0xE0, 0xE0, 0xE0, 0xE0, 0xE6, 0xFE, 0x00},//	L
	{0x00, 0xC6, 0xEE, 0xFE, 0xD6, 0xC6, 0xC6, 0x00},//	M
	{0x00, 0xE6, 0xF6, 0xFE, 0xEE, 0xE6, 0xE6, 0x00},//	N
	{0x00, 0x7C, 0xE6, 0xE6, 0xE6, 0xE6, 0x7C, 0x00},//	O
	{0x00, 0xFC, 0xE6, 0xE6, 0xFC, 0xE0, 0xE0, 0x00},//	P
	{0x00, 0x7C, 0xE6, 0xE6, 0xEE, 0xEE, 0x7C, 0x0E},//	Q
	{0x00, 0xFC, 0xE6, 0xE6, 0xFC, 0xEC, 0xE6, 0x00},//	R
	{0x00, 0x7C, 0xE2, 0x7C, 0x0E, 0xEE, 0x7C, 0x00},//	S
	{0x00, 0xFE, 0x38, 0x38, 0x38, 0x38, 0x38, 0x00},//	T
	{0x00, 0xE6, 0xE6, 0xE6, 0xE6, 0xE6, 0x7C, 0x00},//	U
	{0x00, 0xE6, 0xE6, 0xE6, 0xE6, 0x7C, 0x38, 0x00},//	V
	{0x00, 0xC6, 0xC6, 0xD6, 0xD6, 0xEE, 0xC6, 0x00},//	W
	{0x00, 0xEE, 0xF4, 0x78, 0x3C, 0x5E, 0xEE, 0x00},//	X
	{0x00, 0xC6, 0xEE, 0x7C, 0x38, 0x38, 0x38, 0x00},//	Y
	{0x00, 0xFE, 0x1C, 0x38, 0x70, 0xE0, 0xFE, 0x00},//	Z
	{0x3C, 0x30, 0x30, 0x30, 0x30, 0x30, 0x3C, 0x00},//	[
	{0x30, 0x30, 0x38, 0x18, 0x1C, 0x0C, 0x0C, 0x00},//	'\'
	{0x3C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x3C, 0x00},//	]
	{0x08, 0x14, 0x22, 0x00, 0x00, 0x00, 0x00, 0x00},//	^
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3E, 0x00},//	_
	{0x0C, 0x06, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00},//	`
	{0x00, 0x00, 0x7C, 0xEC, 0xEC, 0xEC, 0x76, 0x00},//	a
	{0x00, 0xE0, 0xE0, 0xFC, 0xEE, 0xEE, 0xFC, 0x00},//	b
	{0x00, 0x00, 0x7C, 0xEE, 0xE0, 0xEE, 0x7C, 0x00},//	c
	{0x00, 0x0E, 0x0E, 0x7E, 0xEE, 0xEE, 0x7E, 0x00},//	d
	{0x00, 0x00, 0x7C, 0xEE, 0xFE, 0xE0, 0x7E, 0x00},//	e
	{0x00, 0x3C, 0x76, 0x70, 0xFE, 0x70, 0x70, 0x00},//	f
	{0x00, 0x7C, 0xEE, 0xEE, 0x7E, 0x0E, 0xEE, 0x7C},//	g
	{0x00, 0xE0, 0xE0, 0xFC, 0xEE, 0xEE, 0xEE, 0x00},//	h
	{0x00, 0x38, 0x00, 0x38, 0x38, 0x38, 0x38, 0x00},//	i
	{0x00, 0x1C, 0x00, 0x1C, 0x1C, 0xDC, 0xDC, 0x78},//	j
	{0x00, 0xE0, 0xE0, 0xE6, 0xF8, 0xEC, 0xE6, 0x00},//	k
	{0x00, 0x78, 0x38, 0x38, 0x38, 0x38, 0x38, 0x00},//	l
	{0x00, 0x00, 0xFC, 0xD6, 0xD6, 0xD6, 0xD6, 0x00},//	m
	{0x00, 0x00, 0xFC, 0xE6, 0xE6, 0xE6, 0xE6, 0x00},//	n
	{0x00, 0x00, 0x7C, 0xE6, 0xE6, 0xE6, 0x7C, 0x00},//	o
	{0x00, 0x00, 0xFC, 0xEE, 0xEE, 0xFC, 0xE0, 0xE0},//	p
	{0x00, 0x00, 0x7E, 0xEE, 0xEE, 0x7E, 0x0E, 0x0E},//	q
	{0x00, 0x00, 0xEE, 0xF8, 0xF0, 0xE0, 0xE0, 0x00},//	r
	{0x00, 0x00, 0x7E, 0xE0, 0xFE, 0x0E, 0xFC, 0x00},//	s
	{0x00, 0x70, 0x70, 0xFE, 0x70, 0x76, 0x3C, 0x00},//	t
	{0x00, 0x00, 0xEE, 0xEE, 0xEE, 0xEE, 0x7E, 0x00},//	u
	{0x00, 0x00, 0xC6, 0xC6, 0xEE, 0x7C, 0x38, 0x00},//	v
	{0x00, 0x00, 0xC6, 0xD6, 0xD6, 0xEE, 0xC6, 0x00},//	w
	{0x00, 0x00, 0xEE, 0x74, 0x38, 0x5C, 0xEE, 0x00},//	x
	{0x00, 0x00, 0xC6, 0x6E, 0x3C, 0x38, 0x70, 0xE0},//	y
	{0x00, 0x00, 0xFE, 0x1C, 0x38, 0x70, 0xFE, 0x00},//	z
	{0x0C, 0x08, 0x18, 0x30, 0x18, 0x08, 0x0C, 0x00},//	{
	{0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x00},//	|
	{0x18, 0x08, 0x0C, 0x06, 0x0C, 0x08, 0x18, 0x00},//	}
	{0x00, 0x00, 0x30, 0x49, 0x06, 0x00, 0x00, 0x00}//	~
};
}
