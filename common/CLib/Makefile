CC = g++
LIBNAME := libClib
TESTPROG := clibtest

SOURCES = $(wildcard src/*.cpp)
OBJS := $(SOURCES:.cpp=.o)

TEST_SOURCES = $(wildcard test/*.cpp)
TEST_OBJS := $(TEST_SOURCES:.cpp=.o)

CFLAGS := -g -fPIC
LDFLAGS = -L=./ -lClib -Wl,-rpath=./

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@ -Iinclude

lib: default

default: $(OBJS)
	$(CC) $(CFLAGS) -o $(LIBNAME).so $(OBJS) -shared

test: lib $(TEST_OBJS)
	$(CC) -o $(TESTPROG) $(TEST_OBJS) $(LDFLAGS) -Iinclude

clean:
	find \( -type f -executable -o -name "*.o" \) -exec rm -v {} \;
