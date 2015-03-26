LIB = ../lib

CXXFLAGS += \
		 -I$(LIB)/include \
		 -std=c++0x \
		 -O0 \
		 -g

%:
	$(CXX) $(CXXFLAGS) $@.cpp

clean:
	find \( -type f -executable -o -name "core" -o -name "*.[so]" \) -exec rm -v {} \;
