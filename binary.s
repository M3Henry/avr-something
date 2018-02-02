.macro usefile name:req file:req
.section .text.\name

.global \name\()_size
.global \name\()_begin
.global \name\()_end

\name\()_size:
	.short \name\()_end - \name\()_begin
\name\()_begin:
	.incbin "\file"
\name\()_end:
.endm

	usefile pi "pi.txt"
