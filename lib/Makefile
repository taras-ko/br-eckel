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

libStash: $(STASHOBJ)
	$(CC) $(CFLAGS) -o $@.so $(STASHOBJ) -shared

libStack: $(STACKOBJ)
	$(CC) $(CFLAGS) -o $@.so $(STACKOBJ) -shared

stack-test: libStack
	$(CC) -o stacktest src/StackTest.cpp -Iinclude -lStack $(LDFLAGS)

lib: default

default: $(OBJS)
	$(CC) $(CFLAGS) -o $(LIBNAME).so $(OBJS) -shared

stash-test: libStash
	$(CC) test/$@.cpp -o $@  -lStash $(LDFLAGS) -Iinclude
	@./$@

clean:
	find \( -type f -executable -o -name "*.o" -o -name "core" \) -exec rm -v {} \;
