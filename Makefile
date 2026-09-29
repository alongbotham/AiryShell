# Form-Finding Framework Build Configuration 
CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -O3
LIBS = -lm

TARGET = form

SRC_MAIN = main.c
SRC_FORM = form.c
SRC_PLOT = plot.c
SRC_SHOCK = shock.c

SRCS = $(SRC_MAIN) $(SRC_FORM) $(SRC_PLOT) $(SRC_SHOCK)

OBJS = $(SRC_MAIN:.c=.o) $(SRC_FORM:.c=.o) $(SRC_PLOT:.c=.o) $(SRC_SHOCK:.c=.o)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBS)

main.o: main.c form.h plot.h shock.h
	$(CC) $(CFLAGS) -c main.c

form.o: form.c form.h
	$(CC) $(CFLAGS) -c form.c

plot.o: plot.c plot.h
	$(CC) $(CFLAGS) -c plot.c

shock.o: shock.c shock.h
	$(CC) $(CFLAGS) -c shock.c

clean:
	rm -f *.o $(TARGET)

help:
	@echo "Build targets:"
	@echo "  make       - Build the form executable"
	@echo "  make clean - Remove compiled files"
	@echo "  make help  - Show this message"

.PHONY: clean help
