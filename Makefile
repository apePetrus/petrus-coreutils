CC = cc
CFLAGS = -std=c99 -Wall -Wextra -Wpedantic -O2

PREFIX ?= /usr/local
BINDIR = $(PREFIX)/bin

PROGS = pecho pcat pls

OBJS = $(addprefix obj/,$(addsuffix .o,$(PROGS)))

all: $(PROGS)

$(PROGS): %: obj/%.o
	$(CC) $(LDFLAGS) -o $@ $< $(LDLIBS)

obj/%.o: src/%.c
	mkdir -p obj
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf obj $(PROGS)

install: all
	install -d $(DESTDIR)$(BINDIR)
	install -m 755 $(PROGS) $(DESTDIR)$(BINDIR)

uninstall:
	rm -f $(addprefix $(DESTDIR)$(BINDIR)/,$(PROGS))

.PHONY: all clean install uninstall
.SECONDARY: $(OBJS)

