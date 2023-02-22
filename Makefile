CC		= gcc
CFLAGS	= -g -Wall

all: \
	is_palindrome \
	longest_common_prefix \
	merge_two_sorted_lists \
	roman_to_integer \
	two_sum \
	valid_parentheses

char_stack:
	$(CC) $(CFLAGS) -c lib/$@.c -o obj/$@.o

int_linked_list:
	$(CC) $(CFLAGS) -c lib/$@.c -o obj/$@.o

is_palindrome: src/is_palindrome.c
	$(CC) $(CFLAGS) src/$@.c -o bin/$@.exe

longest_common_prefix: src/longest_common_prefix.c
	$(CC) $(CFLAGS) src/$@.c -o bin/$@.exe

merge_two_sorted_lists: \
	int_linked_list \
	src/merge_two_sorted_lists.c
	
	$(CC) $(CFLAGS) src/$@.c obj/int_linked_list.o -o bin/$@.exe

roman_to_integer: src/roman_to_integer.c
	$(CC) $(CFLAGS) src/$@.c -o bin/$@.exe

two_sum: src/two_sum.c
	$(CC) $(CFLAGS) src/$@.c -o bin/$@.exe

valid_parentheses: \
	char_stack \
	src/valid_parentheses.c

	$(CC) $(CFLAGS) src/$@.c obj/char_stack.o -o bin/$@.exe

clean:
	rm -f *~ obj/* bin/* *.gch core a.out
