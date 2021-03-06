CFLAGS+=-Wall -Wextra -O2
LDFLAGS+=-lX11

PACKAGE=kb-layout
PROG=main.c

all:
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(PACKAGE) $(PROG)

install: 
	install -D -s -m 755 $(PACKAGE) /usr/bin/$(PACKAGE)

clean:
	rm -f /usr/bin/$(PACKAGE)

.PHONY: all install clean
