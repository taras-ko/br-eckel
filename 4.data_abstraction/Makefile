CC = g++
CLIB = ../common/CLib
CFLAGS = -I$(CLIB)/include -g
LDFLAGS = $(CFLAGS) -L=$(CLIB) -lClib -Wl,-rpath=$(CLIB)

clean:
	find -type f -executable -exec rm {} \;
