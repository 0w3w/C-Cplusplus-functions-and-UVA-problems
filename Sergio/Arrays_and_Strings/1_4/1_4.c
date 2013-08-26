/*
 * Write a method to replace all spaces in a string with'%20'. You may assume that the string has sufficient space at 
 * the end of the string to hold the additional characters, and that you are given the "true" length of the string. 
 * (Note: if imple- menting in Java, please use a character array so that you can perform this opera- tion in place.)
 * EXAMPLE
 * Input: "Mr John Smith  "
 * Output: "Mr%20Dohn%20Smith"
 * */

#include 	<stdlib.h>
#include 	<string.h>
#include 	<stdio.h>

char 		*do_string(char *word, int len)
{
	char 	*new_word;
	int 	index;

	index = 0;
	new_word = (char *)malloc(len + 1);
	if (!new_word)
		return (NULL);
	while (*word != '\0')
	{
		if (*word == ' ')	
		{
			if (*(word + 1) == ' ')
				return (new_word);
			new_word = strncat(new_word, "%20", 3);
			index += 3;
			word++;
		}
		new_word[index] = *word;
		index++;
		word++;
	}
	return (new_word);
}

int 		main(int argc, char **argv)
{
	if (argc != 2)
		return (-1);
	else
	{
		fprintf(stdout, "new string: %s\n", do_string(argv[1], strlen(argv[1])));
		return (0);
	}
}
