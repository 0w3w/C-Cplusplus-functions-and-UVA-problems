/*
 * Get an int as parameter, return the aproximate sqrt
 * Solution in ANSI C
 *
 * y^2 = x
 * 2y^2 = x + y^2
 * y = (x + y^2)/2y 
 *
 * compile and the paremeter must be the number
 * Created by Sergio Baez on 8/24/13
 * https://github.com/sabs231
 */

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
