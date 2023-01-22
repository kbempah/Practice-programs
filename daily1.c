#include <stdio.h>

char* reverse(char* string_to_reverse);
int _strlen(char* string_to_find_length_of);
void swap_characters(char* substr_a , char* substr_b);

/***************************************************************
Function reverse. Accepts and reverses a c-string of any length.
****************************************************************/

char* reverse(char* string_to_reverse)
{
	int start_index = 0, end_index = _strlen(string_to_reverse) - 1;

	while(start_index < end_index)
	{
		swap_characters(string_to_reverse + start_index, string_to_reverse + end_index);
		start_index++; end_index--;
	}

	return string_to_reverse;
}

/********************************************************************
Fucntion _strlen. Returns the integer length of a c-string passed to
it excluding the null-terminating character.
*********************************************************************/

int _strlen(char* string_to_find_length_of)
{
	int string_length = 0;

	for(int count = 0; *(string_to_find_length_of + count) != '\0'; count++) string_length++;
		
	return string_length;
}

void swap_characters(char* substr_a , char* substr_b)
{
	char temp_string = *substr_a;
	*substr_a = *substr_b;
	*substr_b = temp_string;
}

