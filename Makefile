CC=gcc
CFLAGS=-I. -Werror -Wall -Wextra -pedantic
DEPS=src/pe_reader.h src/compatibility_checker.h
OBJ=src/main.o src/pe_reader.o src/compatibility_checker.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

your_app: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) -lpe

.PHONY: clean

clean:
	rm -f *.o your_app