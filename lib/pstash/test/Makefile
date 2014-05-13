CXXFLAGS = -I../include -I../../include
LDFLAGS = -lPStash -L=../ -Wl,-rpath=../

stash-test.o : stash-test.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

stash-test: stash-test.o
	$(CXX) $< -o $@ $(LDFLAGS)

clean:
	rm stash-test.o stash-test

default: stash-test
