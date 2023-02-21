CC		= gcc
CFLAGS	= -g -Wall -Werror

all: \
	is_palindrome \
	longest_common_prefix \
	roman_to_integer \
	two_sum \
	valid_parentheses

is_palindrome: is_palindrome.c
	$(CC) $(CFLAGS) $@.c -o $@.exe

longest_common_prefix: longest_common_prefix.c
	$(CC) $(CFLAGS) $@.c -o $@.exe

roman_to_integer: roman_to_integer.c
	$(CC) $(CFLAGS) $@.c -o $@.exe

two_sum: two_sum.c
	$(CC) $(CFLAGS) $@.c -o $@.exe

valid_parentheses: \
	char_stack \
	valid_parentheses.c

	$(CC) $(CFLAGS) $@.c lib/char_stack.o -o $@.exe

char_stack:
	$(CC) $(CFLAGS) -c lib/$@.c -o lib/$@.o

clean:
	rm -f *~ *.o *.exe *.gch core a.out
