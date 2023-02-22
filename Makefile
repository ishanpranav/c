CC		= gcc
CFLAGS	= -g -Wall

all: \
	is_palindrome \
	longest_common_prefix \
	merge_two_sorted_lists \
	remove_duplicates_from_sorted_array \
	remove_element \
	roman_to_integer \
	search_insert_position \
	two_sum \
	valid_parentheses

char_stack: lib/char_stack.c
	$(CC) $(CFLAGS) -c lib/$@.c -o obj/$@.o

int_array: lib/int_array.c
	$(CC) $(CFLAGS) -c lib/$@.c -o obj/$@.o

int_hashtable: lib/int_hashtable.c
	$(CC) $(CFLAGS) -c lib/$@.c -o obj/$@.o

int_linked_list: lib/int_linked_list.c
	$(CC) $(CFLAGS) -c lib/$@.c -o obj/$@.o

is_palindrome: src/is_palindrome.c
	$(CC) $(CFLAGS) src/$@.c -o bin/$@.exe

longest_common_prefix: src/longest_common_prefix.c
	$(CC) $(CFLAGS) src/$@.c -o bin/$@.exe

merge_two_sorted_lists: \
	int_linked_list \
	src/merge_two_sorted_lists.c
	
	$(CC) $(CFLAGS) src/$@.c obj/int_linked_list.o -o bin/$@.exe

remove_duplicates_from_sorted_array: src/remove_duplicates_from_sorted_array.c
	$(CC) $(CFLAGS) src/$@.c -o bin/$@.exe

remove_element: src/remove_element.c
	$(CC) $(CFLAGS) src/$@.c -o bin/$@.exe

roman_to_integer: src/roman_to_integer.c
	$(CC) $(CFLAGS) src/$@.c -o bin/$@.exe

search_insert_position: \
	int_array \
	src/search_insert_position.c

	$(CC) $(CFLAGS) src/$@.c obj/int_array.o -o bin/$@.exe

two_sum: \
	int_hashtable \
	src/two_sum.c

	$(CC) $(CFLAGS) src/$@.c -o bin/$@.exe

valid_parentheses: \
	char_stack \
	src/valid_parentheses.c

	$(CC) $(CFLAGS) src/$@.c obj/char_stack.o -o bin/$@.exe

clean:
	rm -f *~ obj/* bin/* *.gch core a.out
