CC = g++
CLIB=../lib
CFLAGS = -I$(CLIB)/include -g
LDFLAGS = $(CFLAGS) -L=$(CLIB) -lStack -Wl,-rpath=$(CLIB)

clean:
	find \( -type f -executable -o -name "core" \) -exec rm -v {} \;
