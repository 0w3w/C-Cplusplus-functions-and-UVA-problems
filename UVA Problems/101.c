/*
 *  The Blocks Problem - 101
 *  Solution on ANSI C
 *  
 *  Created by Guillermo Hernandez on 4/5/13
 *  https://github.com/0w3w
 *  http://www.linkedin.com/in/guillermohernandezmolina
 *
 */
#include <stdio.h>
#include <string.h>
#define TRUE	1
#define	FALSE	0

typedef struct blockStruct {
	int blocknum;
	int i;
	int j;
} blockStruct;

/* 0 < n < 25 */
int n, ainput, binput;
int blocks[25][25];
char cmd01[5];
char cmd02[5];
blockStruct aCoord = {.blocknum = -1, .i = -1, .j = -1};
blockStruct bCoord = {.blocknum = -1, .i = -1, .j = -1};

/*
 Initialice the Block Matrix
 */
void initBlocks(int n){
	int i,j;
	for(i=0; i<25; i++){
		for(j=0; j<25; j++){
			if(j == 0 && i < n){
				blocks[i][j] = i;
			}else {
				blocks[i][j] = -1;
			}
		}
	}
}

/*
 Find the i and j of a block
 */
void findCoordinates(int blocknum, blockStruct *coord){
	int i = 0;
	int j = 0;
	int loop = TRUE;	
	while (i < 25 && loop) {
		while (blocks[i][j] != -1 && loop) {
			if(blocks[i][j] == blocknum){
				coord->blocknum = blocknum;
				coord->i = i;
				coord->j = j;
				loop = FALSE;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

/*
 A == B OR pile(A) == pile(B)
 */
int isIllegalCommand(blockStruct *aCoord, blockStruct *bCoord){
	if(aCoord->blocknum == bCoord->blocknum || aCoord->i == bCoord->i){
		return TRUE;
	}	
	return FALSE;
}

/* 
 Return to initial Place
 */
void resetPlaces(int i, int j){
	int tmpVal = -1;
	while(blocks[i][j] != -1){
		tmpVal = blocks[i][j];
		blocks[tmpVal][0] = tmpVal;
		blocks[i][j] = -1;
		j++;
	}
}

/*
 Print the result in the given format
 */
void printResult(){
	int i,j;
	for(i=0; i<n; i++){
		printf("%d:", i);
		for(j=0; j<n; j++){
			if(blocks[i][j] != -1){
				printf(" %d", blocks[i][j]);
			}
		}
		printf("\n");
	}
}

/*
 Mueve A arriba de B,
 Regresa bloques arriba de A y B a sus posiciones iniciales
 */
void moveOnto(blockStruct *aCoord, blockStruct *bCoord){
	/* Muevo elementos arriba de A y B a sus posiciones iniciales */
	resetPlaces(aCoord->i, aCoord->j+1);
	resetPlaces(bCoord->i, bCoord->j+1);
	/* Muevo A arriba de B */
	blocks[bCoord->i][bCoord->j+1] = aCoord->blocknum;
	blocks[aCoord->i][aCoord->j] = -1;
}

/*
 Mueve A arriba de la pila de B,
 Regresa bloques arriba de A a sus posiciones iniciales
 */
void moveOver(blockStruct *aCoord, blockStruct *bCoord){
	/* Muevo elementos arriba de A a sus posiciones iniciales */
	resetPlaces(aCoord->i, aCoord->j+1);
	/* Muevo A arriba de B */
	int bi = bCoord->i;
	int bj = bCoord->j;
	while(blocks[bi][bj] != -1){
		bj++;
	}
	blocks[bi][bj] = aCoord->blocknum;
	blocks[aCoord->i][aCoord->j] = -1;
}

/*
 Mueve pila de A (incluida A) arriba de B,
 Regresa bloques arriba de B a sus posiciones iniciales
 Los bloques de A mantienen en orden al moverse
 */
void pileOnto(blockStruct *aCoord, blockStruct *bCoord){
	/* Muevo elementos arriba de B a sus posiciones iniciales */
	resetPlaces(bCoord->i, bCoord->j+1);
	/* Muevo A y sus top elementos arriba de B */
	int k = 0;
	while(blocks[aCoord->i][aCoord->j+k] != -1){
		blocks[bCoord->i][bCoord->j+k+1] = blocks[aCoord->i][aCoord->j+k];
		blocks[aCoord->i][aCoord->j+k] = -1;
		k++;
	}
}

/*
 Mueve pila de A (incluida A) arriba de la pila de B,
 Los bloques de A y B mantienen en orden al moverse
 */
void pileOver(blockStruct *aCoord, blockStruct *bCoord){
	/* Muevo A y sus top elementos arriba de B */
	int bj = bCoord->j;
	while (blocks[bCoord->i][bj] != -1) {
		bj++;
	}
	int k = 0;
	while(blocks[aCoord->i][aCoord->j+k] != -1){
		blocks[bCoord->i][bj+k] = blocks[aCoord->i][aCoord->j+k];
		blocks[aCoord->i][aCoord->j+k] = -1;
		k++;
	}
}



int main (int argc, const char * argv[]) {
	/* Numero de filas inicial */
	scanf("%d", &n);
	if(n < 1){
		return 0;
	}
	initBlocks(n);
	/* Loop Infinito */
	while (1) {
		scanf("%s", cmd01);
		if (strcmp(cmd01,"quit")==0) {
			break;
		}
		if(scanf("%d %s %d", &ainput, cmd02, &binput)!=3){
			continue;
		}
		findCoordinates(ainput, &aCoord);
		findCoordinates(binput, &bCoord);
		if(isIllegalCommand(&aCoord, &bCoord)){
			continue;
		}else if (strcmp(cmd01,"move")==0 && strcmp(cmd02,"onto")==0) {
			moveOnto(&aCoord, &bCoord);
		}else if (strcmp(cmd01,"move")==0 && strcmp(cmd02,"over")==0) {
			moveOver(&aCoord, &bCoord);
		}else if (strcmp(cmd01,"pile")==0 && strcmp(cmd02,"onto")==0) {
			pileOnto(&aCoord, &bCoord);
		}else if (strcmp(cmd01,"pile")==0 && strcmp(cmd02,"over")==0) {
			pileOver(&aCoord, &bCoord);
		}
	}
	/* Print Result */
	printResult();
	return 0;
}
