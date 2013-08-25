/*
 *Given two strings, write a method to decide if one is a permutation of the other.
 */


#include <stdio.h>

int 		is_anagram(char *w1, char *w2)
{
	char 	*aux;
	int 	flag;

	while (*w1 != '\0')
	{
		flag = 0;
		aux = w2;
		while (*aux != '\0')
		{
			if (*w1 == *aux)
			{
				*aux = '_';
				flag = 1;
			}
			aux++;
		}
		if (flag == 0)
			return (0);
		w1++;
	}
	return (1);
}

int 		main(int argc, char **argv)
{
	if (argc != 3)
		return (-1);
	else
	{
		if (is_anagram(argv[1], argv[2]))
		{
			fprintf(stdout, "they are anagrams\n");
			return (0);
		}
		fprintf(stdout, "they are NOT anagrams\n");
	}
	return (0);
}
