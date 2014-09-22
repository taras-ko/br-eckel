SRCS := $(wildcard *.cpp)
OBJS := $(SRCS:.cpp=.o)

CXXFLAGS := \
		-I../lib/include \
		-std=c++0x

# add PStash lib
CXXFLAGS += \
		-I../lib/pstash/include \
		-L../lib/pstash -lPStash \
		-Wl,-rpath=../lib/pstash

# add Stack
CXXFLAGS += \
		-I../lib/stack/include \
		-L../lib/stack -lStack \
		-Wl,-rpath=../lib/stack

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@

default: $(OBJS)
	$(CXX) $(OBJS)

$<:
	$(CXX) $(CXXFLAGS) $@.cpp

clean:
	@find \( \
		-type f \
		-executable -o \
		-name "*.so" -o \
		-name "*.o" -o \
		-name "core" \
		\) \
	   	-exec rm -v {} \;
