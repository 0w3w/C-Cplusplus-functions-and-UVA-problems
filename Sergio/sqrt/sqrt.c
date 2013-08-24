#include 	<stdio.h>
#include 	<stdlib.h>

int 	main(int argc, char **argv)
{
	float 	temp;
	float 	y;
	float 	x;

	if (argc != 2)
		return (1);
	else
	{
		y = 1;
		x = atof(argv[1]);
		do
		{
			temp = y;
			y = 0.5 * ((x / y) + y);
		} while (y != temp);
		printf("sqrt of %f = %f\n", x, y);
	}
	return (0);
}
