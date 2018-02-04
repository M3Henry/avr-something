CC = avr-gcc
CFLAGS = -Os -DF_CPU=12000000 -flto
CPPFLAGS = -std=c++14
TARGET_ARCH = -mmcu=atmega644p

DEPFLAGS = -MT $@ -MMD -MP -MF .$*.d

COMPILE.c = $(CC) $(DEPFLAGS) $(CFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -c

# Create our phony targets to avoid files interfering
.PHONY: clean install

# Generate a list of sources and objects
C_SOURCES = $(wildcard *.c)
CPP_SOURCES = $(wildcard *.cpp)
ASM_SOURCES = $(wildcard *.s)
OBJECTS = $(C_SOURCES:%.c=.%.o) $(CPP_SOURCES:%.cpp=.%.o) $(ASM_SOURCES:%.s=.%.o)

program.hex: program.elf
	@ avr-objcopy -O ihex program.elf program.hex

# The final target, with dependancies generated from the sources list
program.elf: $(OBJECTS)
	@ $(CC) $(CFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -Wl,--gc-sections -o $@ $^

# The install target
install: program.hex
	@ avrdude -c usbasp -p m644p -U $<

# Clean up everything that we generate
clean:
	@ rm -f program.hex program.elf .*.o .*.d

# Delete the built-in rules for building object files from .c files...
%.o : %.c
# ...so that our rule is used instead.
.%.o : %.c .%.d makefile
	@ $(COMPILE.c) $(OUTPUT_OPTION) $<

%.o : %.cpp
.%.o : %.cpp .%.d makefile
	@ $(COMPILE.c) $(OUTPUT_OPTION) $<

%.o : %.s
.%.o : %.s .%.d makefile
	@ avr-as --MD .$*.d -c -o $@ $<

# Create a pattern rule with an empty recipe, so that
# `make` won’t fail if the dependency file doesn’t exist.
.%.d: ;

# Mark the dependency files precious, so they won’t be
# automatically deleted as intermediate files.
.PRECIOUS: .%.d

# Include all of the dependency files
include $(wildcard .*.d)
