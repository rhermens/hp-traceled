CC=gcc
CFLAGS=-I. -lhidapi-libusb -pedantic-errors -Wall
DEPS=
DESTDIR=/usr/bin

hp-traceled: hp-traceled.c $(DEPS)
	$(CC) -o hp-traceled hp-traceled.c $(DEPS) $(CFLAGS)

# install:
# 	cp git-watch $(DESTDIR)

clean:
	rm hp-traceled
