sources := $(wildcard src/*.cpp)
objects := $(sources:.cpp=.o)

sobjects := $(objects:src/%=%)
sobjects := $(addprefix lib, $(sobjects))
sobjects := $(sobjects:.o=.so)

CXXFLAGS = -Iinclude -I../include -fPIC
LDFLAGS = -shared

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

lib%.so: src/%.o
	$(CXX) $(LDFLAGS) $< -o $@

default: $(objects) $(sobjects)


clean:
	find \( \
		-type f \
		-executable -o \
		-name "*.so" -o \
		-name "*.o" -o \
		-name "core" \
		\) \
	   	-exec rm -v {} \;
