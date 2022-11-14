NAME := foo
HEADERFILES := src/greeter.h
OBJFILES := obj/main.o obj/greeter.o
LDFLAGS ?=
CFLAGS ?= -Wall -Wextra -Werror
CC := gcc

$(NAME): $(OBJFILES)
	$(CC) $(LDFLAGS) -o $@ $^

obj/%.o: src/%.c $(HEADERFILES)
	@mkdir -p $(dir $@)
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	rm -f $(NAME) $(OBJFILES)

.PHONY: clean
