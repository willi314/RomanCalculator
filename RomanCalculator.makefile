CFLAGS=-Wall
LIBS=-lcheck

all: RomanCalculator

RomanCalculator: main.o RomanConverter.o
	gcc -o RomanCalculator main.o RomanConverter.o

main.o: main.c RomanConverter.h
	gcc $(CFLAGS) -c main.c

RomanConverter.o: RomanConverter.c RomanConverter.h
	gcc $(CFLAGS) -c RomanConverter.c

test: RomanCalculator-test
	./RomanCalculator-test

RomanCalculator-test: RomanCalculator-test.o RomanConverter.o
	gcc -o RomanCalculator-test RomanConverter.o RomanCalculator-test.o $(LIBS) -lm -lrt -lpthread

RomanCalculator-test.o: RomanCalculator-test.c RomanConverter.h
	gcc $(CFLAGS)-c RomanCalculator-test.c