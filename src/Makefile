CC		= gcc
CFLAGS	= -g -Wall -Werror

all: \
	is_palindrome \
	longest_common_prefix \
	merge_two_sorted_lists \
	roman_to_integer \
	two_sum \
	valid_parentheses

char_stack:
	$(CC) $(CFLAGS) -c lib/$@.c -o lib/$@.o

int_list:
	$(CC) $(CFLAGS) -c lib/$@.c -o lib/$@.o

is_palindrome: is_palindrome.c
	$(CC) $(CFLAGS) $@.c -o $@.exe

longest_common_prefix: longest_common_prefix.c
	$(CC) $(CFLAGS) $@.c -o $@.exe

merge_two_sorted_lists: \
	int_list \
	merge_two_sorted_lists.c
	
	$(CC) $(CFLAGS) $@.c -o $@.exe

roman_to_integer: roman_to_integer.c
	$(CC) $(CFLAGS) $@.c -o $@.exe

two_sum: two_sum.c
	$(CC) $(CFLAGS) $@.c -o $@.exe

valid_parentheses: \
	char_stack \
	valid_parentheses.c

	$(CC) $(CFLAGS) $@.c lib/char_stack.o -o $@.exe

clean:
	rm -f *~ *.o *.exe *.gch core a.out
