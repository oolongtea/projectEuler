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

.PHONY: default
default: one two three

# header dependency
# (none)

.PHONY: clean
clean:
	rm -f *.o *~ a.out core one two three

.PHONY: all
all: clean default
