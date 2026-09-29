# Form-Finding Framework Build Configuration
CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -O2
LIBS = -lm -lglfw

TARGET = form

SRC_MAIN = main.c
SRC_FORM = form.c
SRC_PLOT = plot.c
SRC_SHOCK = shock.c

OBJS = main.o form.o plot.o shock.o

$(TARGET): $(OBJS)
	    $(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBS)

# Compile main.c
main.o: main.c form.h plot.h shock.h
	    $(CC) $(CFLAGS) -c main.c -o main.o

form.o: form.c form.h
	    $(CC) $(CFLAGS) -c form.c -o form.o

plot.o: plot.c plot.h
	    $(CC) $(CFLAGS) -c plot.c -o plot.o

shock.o: shock.c shock.h
	    $(CC) $(CFLAGS) -c shock.c -o shock.o

clean:
	    rm -f *.o $(TARGET)

.PHONY: clean
