CC = g++
CSTASHLIB := libClib
STASHLIB := libStash
TESTPROG := clibtest

MEMSRC = src/Mem.cpp
MEMOBJ = $(MEMSRC:.cpp=.o)

STASHSRC = src/Stash.cpp
STASHOBJ = $(STASHSRC:.cpp=.o)

STACKSRC = src/Stack.cpp
STACKOBJ = $(STACKSRC:.cpp=.o)

SOURCES = $(wildcard src/*.cpp)
OBJS := $(SOURCES:.cpp=.o)

CFLAGS := -g -fPIC
LDFLAGS = -L=./ -Wl,-rpath=./

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@ -Iinclude

Mem: $(MEMOBJ)
	$(CC) $(CFLAGS) -o lib$@.so $(MEMOBJ) -shared

Stash: $(STASHOBJ)
	$(CC) $(CFLAGS) -o lib$@.so $(STASHOBJ) -shared

Stack: $(STACKOBJ)
	$(CC) $(CFLAGS) -o lib$@.so $(STACKOBJ) -shared


lib: default

default: $(OBJS)
	$(CC) $(CFLAGS) -o $(LIBNAME).so $(OBJS) -shared

test: mem-test stash-test stack-test

mem-test: Mem
	$(CC) -g test/$@.cpp -o $@  -lMem $(LDFLAGS) -Iinclude

stash-test: Stash
	$(CC) test/$@.cpp -o $@  -lStash -lMem $(LDFLAGS) -Iinclude

stack-test: Stack
	$(CC) test/$@.cpp -o $@  -lStack $(LDFLAGS) -Iinclude

clean:
	find \( -type f -executable -o -name "*.o" -o -name "core" \) -exec rm -v {} \;
