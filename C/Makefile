#
# Makefile for Project Euler Problems 
#

CC = gcc
CXX = g++

INCLUDES = 
CFLAGS = -g -Wall $(INCLUDES)
CXXFLAGS = -g -Wall $(INCLUDES)

LDFLAGS = -g
LDLIBS = -lm

DEFAULTS = one two three four five six seven

.PHONY: default
default: $(DEFAULTS)

# header dependency
# (none)

.PHONY: clean
clean:
	rm -f *.o *~ a.out core $(DEFAULTS)

.PHONY: all
all: clean default
