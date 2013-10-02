/*
 *  MergeSort of a Linked List
 *  Solution on ANSI C
 *  
 *  Usage:
 *  mergeSortLL(node); 
 *  
 *  Created by Guillermo Hernandez on 10/01/13
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

Node* getMiddle(Node* head, Node* tail){
	Node *fastEnd = head->next;
	while(fastEnd != tail){
		head = head->next;
		fastEnd = fastEnd->next;
		if(fastEnd != tail && fastEnd->next != NULL)
			fastEnd = fastEnd->next;
	}
	return head;
}

Node* mergeSortLL(Node *head, Node *tail, int deep){
	if(head == NULL || tail == NULL || deep > 10){
		return NULL;
	}else if(head == tail){
		head->next = NULL;
		return head;
	}else if(head->next == tail){
		tail->next = NULL;
		if(head->value <= tail->value){
			return head;
		}else{
			Node *newHead;
			newHead = tail;
			newHead->next = head;
			head->next = NULL;
			return newHead;
		}
	}
	Node *middle	= getMiddle(head, tail);
	Node *middleN	= middle->next;
	Node *leftSort 	= mergeSortLL(head,middle, deep+1);
	Node *rightSort = mergeSortLL(middleN,tail,deep+1);
	Node *newHead, *iterator, *tmpNode;
	if(leftSort->value <= rightSort->value){
		newHead = leftSort;
		leftSort = leftSort->next;
		iterator = newHead;
	}else{
		newHead = rightSort;
		rightSort = rightSort->next;
		iterator = newHead;
	}
	while(leftSort!=NULL && rightSort !=NULL){
		if(leftSort->value <= rightSort->value){
			iterator->next 	= leftSort;
			iterator	= iterator->next;
			leftSort 	= leftSort->next;
			iterator->next	= NULL;
		}else{
			iterator->next 	= rightSort;
			iterator	= iterator->next;
			rightSort 	= rightSort->next;
			iterator->next	= NULL;
		}
	}
	if(leftSort != NULL){
		iterator->next = leftSort;
	}else{
		iterator->next = rightSort;
	}
	return newHead;
}

int main(){
	Node A,B,C,D,E,F;
	F.value = 'E';
	E.value = 'F';
	D.value = 'A';
	C.value = 'C';
	B.value = 'B';
	A.value = 'D';
	A.next = &B;
	B.next = &C;
	C.next = &D;
	D.next = &E;
	E.next = &F;
	F.next = NULL;

	fprintf(stdout,"Original List: \n");
	printLL(&A);
	fprintf(stdout,"MergeSorted: \n");
	Node *sortedHead = mergeSortLL(&A,&F,0);
	printLL(sortedHead);	
	return 0;
}
