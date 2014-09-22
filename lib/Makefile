CSTASHLIB := libClib
STASHLIB := libStash
TESTPROG := clibtest

MEMSRC = src/Mem.cpp
MEMOBJ = $(MEMSRC:.cpp=.o)

STASHSRC = src/Stash.cpp
STASHOBJ = $(STASHSRC:.cpp=.o)

STACKSRC = stack/src/Stack.cpp
STACKOBJ = $(STACKSRC:.cpp=.o)

SOURCES = $(wildcard src/*.cpp)
OBJS := $(SOURCES:.cpp=.o)

CXXFLAGS := -g -fPIC
LDFLAGS = -L=./ -Wl,-rpath=./

Mem: $(MEMOBJ)
	$(CXX) -o lib$@.so $(MEMOBJ) -shared

Stash: $(STASHOBJ)
	$(CXX) -o lib$@.so $(STASHOBJ) -shared

Stack: $(STACKOBJ)
	$(CXX) -o lib$@.so $(STACKOBJ) -shared


lib: default

default: $(OBJS)
	$(CC) $(CFLAGS) -o $(LIBNAME).so $(OBJS) -shared

test: mem-test stash-test stack-test

mem-test: Mem
	$(CC) -g test/$@.cpp -o $@  -lMem $(LDFLAGS) -Iinclude

stash-test: Mem Stash
	$(CC) test/$@.cpp -o $@  -lStash -lMem $(LDFLAGS) -Iinclude

stack-test: Stack
	$(CC) test/$@.cpp -o $@  -lStack $(LDFLAGS) -Iinclude
