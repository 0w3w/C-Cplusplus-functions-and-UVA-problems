/*
 *Write code to remove duplicates from an unsorted linked list (pointers aproach).
 * */

#include 	"2_1.hh"

void 		Node::appendToTail(int d)
{
	Node 	*end = new Node(d);
	Node 	*n = this;

	while (n->next != NULL)
		n = n->next;
	n->next = end;
}

void 		Node::printL()
{
	Node 	*temp = this;

	while (temp != NULL)
	{
		std::cout << temp->data << "->";
		temp = temp->next;
	}
	std::cout << std::endl;
}

void 		Node::clearList()
{
	Node 	*temp = this;
	Node 	*aux;

	while (temp->next != NULL)
	{
		aux = temp;
		if (temp->next != NULL)
			temp = temp->next;
			delete aux;
	}
}

void 		Node::deleteNode(Node *temp)
{
	Node 	*aux;

	aux = temp->next;
	if (temp->next != NULL)
	{
		temp->next = temp->next->next;
		delete aux;
	}
	temp = temp->next;
}

Node 		*Node::remove(Node *head)
{
	Node 	*pivot = head;
	Node 	*temp;

	if (head->next == NULL)
		return (head);
	while (pivot != NULL)
	{
		temp = pivot;
		while (temp->next != NULL)
		{
			if (temp->next->data == pivot->data)
				deleteNode(temp);
			else
				temp = temp->next;
		}
		pivot = pivot->next;
	}
	return (head);
}
		
int 		main(int argc, char **argv)
{
	int 	i;
	Node 	*list;

	if (argc == 1)
		return (-1);
	i = 2;
	list = new Node(atoi(argv[1]));
	while (i < argc)
	{
		list->appendToTail(atoi(argv[i]));
		i++;
	}
	list->printL();
	list = list->remove(list);
	list->printL();
	return (0);
}
