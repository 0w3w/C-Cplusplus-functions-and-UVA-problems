/*
 implement a function void reverse(char* str) in C or C++ 
 which reverses a null- terminated string
 */

#include 	<stdio.h>

int 		my_len(char *str)
{
	int 	len;

	len = 0;
	while (*str != '\0')
	{
		len++;
		str++;
	}
	return (len);
}

void 		my_swap(char *a, char *b)
{
	char 	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void 		reverse(char *str)
{
	int 	i;
	int 	j;

	i = 0;
	j = my_len(str) - 1;
	while (i < j)
	{
		my_swap(&str[i], &str[j]);
		i++;
		j--;
	}
	fprintf(stdout, "string reversed: [%s]\n", str);
}

int 		main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	else
		reverse(argv[1]);
	return (0);
}
