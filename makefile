CC          := gcc
CFLAGS      := -O2 -Wall -Wextra -Werror -MMD -MP -Iinclude
TARGET      := build/game

# Simple Unix recursive wildcard function
rwildcard = $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2) $(filter $2,$d))

# Collect sources and map them to build objects
SRCS := $(call rwildcard,src/,%.c)
OBJS := $(patsubst src/%.c,build/obj/%.o,$(SRCS))
DEPS := $(OBJS:.o=.d)

all: $(TARGET)

# Link binary
$(TARGET): $(OBJS)
	@mkdir -p build
	$(CC) $(OBJS) -o $(TARGET)

# Compile objects and dynamically mirror the nested src/ folder structure
build/obj/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

-include $(DEPS)

clean:
	rm -rf build

.PHONY: all clean

