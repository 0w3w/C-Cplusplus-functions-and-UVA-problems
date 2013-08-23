/*
 *  Get an int number as parameter, return the aproximate sqrt.
 *  Solution on ANSI C
 *  
 *  Check if parameter exists in query string and return it's value
 *  Usage:
 *  my_sqrt(2916); 
 *  
 *  Created by Guillermo Hernandez on 8/22/13
 *  https://github.com/0w3w
 *  http://www.linkedin.com/in/guillermohernandezmolina
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAXCICLE 1000

double my_sqrt_bs(int number){
	double result = 0.0, pastResult, testResult, tmp;
	unsigned int cicleCount = 0;
	if (number == 1){ // Some heuristics over here.
		return 1;
	}else{
		result		= number/2;
		pastResult	= result;
		testResult = abs(result*result);
		while(testResult != number && cicleCount < MAXCICLE){ // Binary search
			if(testResult > number){
				pastResult = result;
				result = result/2;

			}else{
				tmp = result;
				result = ((pastResult-result)/2) + result;
				pastResult = tmp;
			}
			testResult = abs(result*result);
			cicleCount++;
		}
	}
	return result;
}

double my_sqrt_brute(int num){
    double mod=1;
    double result=0;
	int	i;
    for(i=0; i<num/2; result+=mod, i++){
		if(result*result>num){
			result-=mod;
			mod/=10;
		}
	}
    return result;
}



int main(){
	printf("Sqrt for 2916 - BS: %f\n", my_sqrt_bs(27394));
	printf("Sqrt for 2916 - Brute: %f\n", my_sqrt_brute(27394)); 
	printf("Sqrt for 2916 - Native: %f\n", sqrt(27394));
	return 0;
}
