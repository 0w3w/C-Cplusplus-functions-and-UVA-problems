#include 			<stdio.h>

typedef struct 	dic 
{
	char 					letter;
	int 					number;
} 							Dic;

void 						init_dic(Dic *a, int len)
{
	int 					i;

	i = 0;
	while (i < len)
	{
		a[i].letter = '\0';
		a[i].number = 0;
		i++;
	}
}

int 						main(int argc, char **argv)
{
	Dic 					dictionary[256];
	char 					*word;

	if (argc != 2)
		return (-1);
	else
	{
		init_dic(&dictionary[0], 256);
		word = argv[1];
		while (*word != '\0')
		{
			if (dictionary[*word].number == 1)
			{
				fprintf(stdout, "0\n");
				return (0);
			}
			dictionary[*word].number++;
			word++;
		}
	}
	fprintf(stdout, "1\n");
	return (0);
}
