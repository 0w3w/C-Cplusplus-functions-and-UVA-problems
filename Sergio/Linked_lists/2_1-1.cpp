
/*THIS IS NO FINISHED HAS A MEMORY LEAK!*/

#include 	<map>
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

void 		Node::removeWithHash()
{
	std::map<int, int> 	dp;
	Node 								*temp;
	Node 								*aux;

	temp = this;
	if (temp->next == NULL)
		return ;
	dp[temp->data] = 1;
	while (temp != NULL)
	{
		if (dp[temp->next->data] == 1)
		{
			aux = temp;
			temp->next = temp->next->next;
			if (aux)
				delete aux;
		}
		else
			dp[temp->next->data] = 1;
		temp = temp->next;
	}
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
	list->removeWithHash();
	list->printL();
	return (0);
}
