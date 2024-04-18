# makefile for sample cpputest

CPPUTEST_HOME = /home/wangyubin/Downloads/cpputest-3.6

CC      := gcc
CFLAGS    := -g -Wall
CFLAGS  += -std=c99
CPP     := g++
CPPFLAGS  := -g -Wall
CPPFLAGS  += -I$(CPPUTEST_HOME)/include

LDFLAGS := -L$(CPPUTEST_HOME)/lib -lCppUTest

app: app.o sample.o
	$(CPP) -o $@ app.o sample.o $(LDFLAGS)

app.o: sample.h app.c
	$(CPP) -c -o app.o app.c $(CPPFLAGS)

.PHONY: clean
clean:
	@echo "clean..."
	rm -f app sample
	rm -f *.o
