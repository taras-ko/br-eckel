CC = g++

LIBPATH = ../lib

CXXFLAGS += \
		 -std=c++0x \
		 -I$(LIBPATH)/include \
		 -O0 \
		 -g
		 #-Wall\

%:
	$(CXX) $(CXXFLAGS) $@.cpp

clean:
	find \( -type f -executable -o -name "core" -o -name "*.[so]" \) -exec rm -v {} \;
