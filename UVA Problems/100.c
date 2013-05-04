/*
 *  The 3n + 1 problem - 100
 *  Solution on ANSI C
 *  
 *  Created by Guillermo Hernandez on 5/1/13
 *  https://github.com/0w3w
 *  http://www.linkedin.com/in/guillermohernandezmolina
 *
 */

#include <stdio.h>

int iterationNumberOfN(int n){
	if(n == 1){
		return 1;
	}else if(n % 2 == 0){
		/* Even */
		return 1 + iterationNumberOfN(n/2);
	}else{
		/* Odd */
		return 1 + iterationNumberOfN(n*3+1);
	}
}


int main(){
	int i, j, swapedi, swapedj, max, ic, iterationNumber;
	while (scanf("%d %d\n",&i,&j)==2){
		max = 1;
		swapedi = i;
		swapedj = j;
		if(swapedi > swapedj){
			swapedi = j;
			swapedj = i;
		}
		iterationNumber = 1;
		for (ic = swapedi; ic <= swapedj; ic++) {
			iterationNumber = iterationNumberOfN(ic);
			if(iterationNumber > max){
				max = iterationNumber;
			}
		}
		printf("%d %d %d\n", i, j, max);
	}
	return(0);
}