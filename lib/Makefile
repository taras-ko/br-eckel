CC = g++
CSTASHLIB := libClib
STASHLIB := libStash
TESTPROG := clibtest

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

Stash: $(STASHOBJ)
	$(CC) $(CFLAGS) -o lib$@.so $(STASHOBJ) -shared

Stack: $(STACKOBJ)
	$(CC) $(CFLAGS) -o lib$@.so $(STACKOBJ) -shared

stack-test: Stack
	$(CC) -o stacktest src/StackTest.cpp -Iinclude -lStack $(LDFLAGS)

lib: default

default: $(OBJS)
	$(CC) $(CFLAGS) -o $(LIBNAME).so $(OBJS) -shared

stash-test: Stash
	$(CC) test/$@.cpp -o $@  -lStash $(LDFLAGS) -Iinclude
	@./$@

clean:
	find \( -type f -executable -o -name "*.o" -o -name "core" \) -exec rm -v {} \;
