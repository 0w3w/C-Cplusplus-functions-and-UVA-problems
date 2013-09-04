/*
 *  Reverse a Linked List
 *  Solution on ANSI C
 *  
 *  Usage:
 *  reverse_01(node); 
 *  reverse_01(node); 
 *  
 *  Created by Guillermo Hernandez on 9/04/13
 *  https://github.com/0w3w
 *  http://www.linkedin.com/in/guillermohernandezmolina
 *
 */

#include <stdio.h>

typedef struct Node{
	Node *next;
	char value;
} Node;

void printLL(Node *head){
	Node *tmp = head;
	while(tmp != NULL){
		fprintf(stdout,"%c -> ", tmp->value);
		tmp = tmp->next;	
	}
	fprintf(stdout," null \n");	
}

Node * reverse_01(Node *head){
	Node *tmpPop, *newList;
	newList = NULL;
	tmpPop = NULL;
	if(head == NULL && head->next == NULL){
		fprintf(stdout," Empty List \n");	
		return head;
	}
	do{
		tmpPop = head;
		head = tmpPop->next;
		tmpPop->next = newList;
		newList = tmpPop;
	}while(head !=NULL);
	head = tmpPop;
	return head;	
}

Node*  reverse_02(Node *head){
	if(head == NULL || head->next == NULL) return head;
	Node *tmpHead	    = head;
	Node *oneBeforeLast = NULL;
	while(head->next != NULL){
		oneBeforeLast = head;
		head = head->next;
	}
	Node *last  = oneBeforeLast->next;
	last->next = tmpHead;
	head = last;
	oneBeforeLast->next = NULL;
	head->next = reverse_02(head->next);
	return head;
}



int main(){
	Node A,B,C,D;
	D.value = 'D';
	C.value = 'C';
	B.value = 'B';
	A.value = 'A';
	A.next = &B;
	B.next = &C;
	C.next = &D;
	D.next = NULL;

	fprintf(stdout,"Original List: \n");
	printLL(&A);
	fprintf(stdout,"Reverse, single iteration: \n");
	Node *reversedHead = reverse_01(&A);
	printLL(reversedHead);	
	fprintf(stdout,"Reverse, O(n^2), Bad aproach: \n");
	printLL(reverse_02(reversedHead));
	return 0;
}
