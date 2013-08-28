/*
 *  Get the difference between 2 trees
 *  Solution on C++
 *
 *  It saves the first branch on a vector.
 *  It iterate the second branch and remove each element that is equal on the vector, if it's not present it is pushed_back to the vector.
 *  At the end, the remaining nodes at the vector are the difference between two trees
 *  
 *  Usage:
 *  1) Build a Random tree
 *  2) dir_diff(treeA,treeB); 
 *  
 *  Created by Guillermo Hernandez on 8/24/13
 *  https://github.com/0w3w
 *  http://www.linkedin.com/in/guillermohernandezmolina
 *
 */

#include <stdio.h>
#include <string>
#include <vector>

typedef struct Node{
	std::string name;
	std::vector<Node> hijos;
}Node;

std::vector<Node> visited;

// Helper Functions

void print_visited(){
	std::vector<Node>::iterator it = visited.begin();
        while(it != visited.end()){
                fprintf(stdout, "%s ", it->name.c_str());
		++it;
        }
}

void print_tree(Node *node, int profundidad){
	int i = 0;
	while(i < profundidad){
		fprintf(stdout,"-");
		i++;
	}
	fprintf(stdout, "%s\n", node->name.c_str());
	std::vector<Node>::iterator it = node->hijos.begin();
	while(it != node->hijos.end()){
		print_tree(&(*it), profundidad+1);
		++it;
	}
}

// Core

int findAndPop(Node *nodo){
	int deleted = 0;
	std::vector<Node>::iterator it = visited.begin();
	while(it != visited.end()){
		if(nodo->name.compare(it->name) == 0){
			it = visited.erase(it);
			deleted = 1;
			break;
		}else{
			++it;
		}
	}
	return deleted;
}

void visit(Node *nodo){
	visited.push_back(*nodo);
	std::vector<Node>::iterator it = nodo->hijos.begin();
	while(it != nodo->hijos.end()){
		visit(&(*it));
		++it;	
	}
}

void getDiff(Node *nodo, int first){
	if(!first){
		if(!findAndPop(nodo)){
			visited.push_back(*nodo);
		}else{
		}
	}
	std::vector<Node>::iterator it = nodo->hijos.begin();
	while(it != nodo->hijos.end()){
		getDiff(&(*it),0);
		++it;	
	}

}

void dir_diff(Node *A, Node *B){
	visit(A);
	getDiff(B,1);
	fprintf(stdout,"\nDir Difference :");
	print_visited();
	fprintf(stdout,"\n");
}


int main(){
	// Build tree
	Node *treeA = new Node();
	Node *treeB = new Node();
	Node *treeA_D1 = new Node();
	Node *treeA_F1 = new Node();
	Node *treeA_F2 = new Node();
	Node *treeB_D1 = new Node();
	Node *treeB_F1 = new Node();
	Node *treeB_F3 = new Node();

	treeA->name = "A";
	treeA_D1->name = "D1";
	treeA_F1->name = "F1";
	treeA_F2->name = "F2";
	
	treeB->name = "B";
	treeB_D1->name = "D1";
	treeB_F1->name = "F1";
	treeB_F3->name = "F3";

	treeA_D1->hijos.push_back(*treeA_F2);
	treeA->hijos.push_back(*treeA_D1);
	treeA->hijos.push_back(*treeA_F1);

	treeB_D1->hijos.push_back(*treeB_F3);
	treeB->hijos.push_back(*treeB_D1);
	treeB->hijos.push_back(*treeB_F1);
	
	// Print Tree
	print_tree(treeA,0);
	print_tree(treeB,0);

	// Solve Difference	
	dir_diff(treeA,treeB);

	return 0;
}
