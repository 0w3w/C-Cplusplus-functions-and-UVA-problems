#include 	<iostream>

class 	Node
{
	public:
		Node 	*next;
		int 	data;

		Node(int d)
		{
			next = NULL;
			data = d;
		}
		void 	appendToTail(int);
		void 	printL();
		void 	clearList();
		void 	deleteNode(Node *temp);
		Node 	*remove(Node *head);
		void 	removeWithHash();
}; 
