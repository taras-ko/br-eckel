CC = g++
CFLAGS = -Wall

%:
	$(CC) $@.cpp $(CFLAGS)

clean:
	find \( -type f -executable -o -name "core" \) -exec rm -v {} \;
