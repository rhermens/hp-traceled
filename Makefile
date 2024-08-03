CC=gcc
CFLAGS=-I. -lhidapi-libusb -pedantic-errors -Wall
DEPS=
DESTDIR=/usr/bin

hp-tracerled: hp-tracerled.c $(DEPS)
	$(CC) -o hp-tracerled hp-tracerled.c $(DEPS) $(CFLAGS)

clean:
	rm hp-tracerled
