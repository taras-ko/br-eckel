CC = g++

CLIB=../lib
CFLAGS = -I$(CLIB)/include -g
#LDFLAGS = $(CFLAGS) -L=$(CLIB) -lStack -lStash -Wl,-rpath=$(CLIB)
%:
	$(CC) $(CFLAGS) $@.cpp
clean:
	find \( -type f -executable -o -name "core" \) -exec rm -v {} \;
