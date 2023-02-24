CC		= gcc
CFLAGS	= -g -Wall
EXT		= .exe

all: \
	is_palindrome \
	length_of_last_word \
	longest_common_prefix \
	merge_two_sorted_lists \
	plus_one \
	remove_duplicates_from_sorted_array \
	remove_element \
	roman_to_integer \
	search_insert_position \
	two_sum \
	valid_parentheses

lib:
	char_stack \
	int_array \
	int_dictionary \
	int_linked_list

char_stack: lib/char_stack.c
	$(CC) $(CFLAGS) -c lib/$@.c -o obj/$@.o

int_array: lib/int_array.c
	$(CC) $(CFLAGS) -c lib/$@.c -o obj/$@.o

int_dictionary: lib/int_dictionary.c
	$(CC) $(CFLAGS) -c lib/$@.c -o obj/$@.o

int_linked_list: lib/int_linked_list.c
	$(CC) $(CFLAGS) -c lib/$@.c -o obj/$@.o

add_binary: src/add_binary.c
	$(CC) $(CFLAGS) src/$@.c -o bin/$@$(EXT)

is_palindrome: src/is_palindrome.c
	$(CC) $(CFLAGS) src/$@.c -o bin/$@$(EXT)

length_of_last_word: src/length_of_last_word.c
	$(CC) $(CFLAGS) src/$@.c -o bin/$@$(EXT)

longest_common_prefix: src/longest_common_prefix.c
	$(CC) $(CFLAGS) src/$@.c -o bin/$@$(EXT)

merge_two_sorted_lists: \
	int_linked_list \
	src/merge_two_sorted_lists.c
	
	$(CC) $(CFLAGS) src/$@.c obj/int_linked_list.o -o bin/$@$(EXT)

plus_one: src/plus_one.c
	$(CC) $(CFLAGS) src/$@.c -o bin/$@$(EXT)

remove_duplicates_from_sorted_array: src/remove_duplicates_from_sorted_array.c
	$(CC) $(CFLAGS) src/$@.c -o bin/$@$(EXT)

remove_element: src/remove_element.c
	$(CC) $(CFLAGS) src/$@.c -o bin/$@$(EXT)

roman_to_integer: src/roman_to_integer.c
	$(CC) $(CFLAGS) src/$@.c -o bin/$@$(EXT)

search_insert_position: \
	int_array \
	src/search_insert_position.c

	$(CC) $(CFLAGS) src/$@.c obj/int_array.o -o bin/$@$(EXT)

two_sum: \
	int_dictionary \
	src/two_sum.c

	$(CC) $(CFLAGS) src/$@.c obj/int_dictionary.o -lm -o bin/$@$(EXT)

valid_parentheses: \
	char_stack \
	src/valid_parentheses.c

	$(CC) $(CFLAGS) src/$@.c obj/char_stack.o -o bin/$@$(EXT)

clean:
	rm -f *~ obj/* bin/* *.gch core a.out
