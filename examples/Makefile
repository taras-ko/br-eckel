CC = g++

LIBPATH = ../lib

CFLAGS += \
		 -std=c++0x \
		 -I$(LIBPATH)/include \
		 -O0 \
		 -g
		 #-Wall\

%:
	$(CC) $(CFLAGS) $@.cpp
clean:
	find \( -type f -executable -o -name "core" -o -name "*.[so]" \) -exec rm -v {} \;
