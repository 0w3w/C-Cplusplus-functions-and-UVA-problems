#include 		<iostream>
#include 		<string.h>
#include 		"3-1.hh"


Stacks::Stacks()
{
	memset(this->myStacks, -1, (MAXSIZE * NUMSTACKS) * sizeof(int));
	memset(this->topStacks, -1, NUMSTACKS * sizeof(int));
}

Stacks::~Stacks()
{
}

void 				Stacks::push(int value, int numStack)
{
	int 			index;

	index = 0;
	while (this->myStacks[index + numStack] != -1)
		index += NUMSTACKS;
	this->myStacks[index + numStack] = value;
	this->topStacks[numStack] = index + numStack;
}

int 				Stacks::pop(int numStack)
{
	int res;

	res = this->myStacks[this->topStacks[numStack]];
	this->myStacks[this->topStacks[numStack]] = -1;
	this->topStacks[numStack] -= NUMSTACKS;
	return (res);
}

int 				Stacks::peek(int numStack)
{
	return (this->myStacks[this->topStacks[numStack]]);
}

void 				Stacks::print()
{
	int 			i;

	i = 0;
	std::cout << "Complete Array: ";
	while (i < MAXSIZE * NUMSTACKS)
	{
		std::cout << this->myStacks[i] << " ";
		i++;
	}
	std::cout << std::endl;
	i = 0;
	std::cout << "Stack 1: ";
	while (i < MAXSIZE * NUMSTACKS)
	{
		std::cout << this->myStacks[i] << " ";
		i+= NUMSTACKS;
	}
	std::cout << std::endl;
	i = 1;
	std::cout << "Stack 2: ";
	while (i < MAXSIZE * NUMSTACKS)
	{
		std::cout << this->myStacks[i] << " ";
		i+= NUMSTACKS;
	}
	std::cout << std::endl;
	i = 2;
	std::cout << "Stack 3: ";
	while (i < MAXSIZE * NUMSTACKS)
	{
		std::cout << this->myStacks[i] << " ";
		i+= NUMSTACKS;
	}
	std::cout << std::endl;
	i = 0;
	while (i < NUMSTACKS)
	{
		std::cout << this->topStacks[i] << " ";
		i++;
	}
	std::cout << std::endl;
}

int 				main(int argc, char **argv)
{
	Stacks 		*s;
	int 			i;

	s = new Stacks();
	s->print();
	i = 0;
	while (i < MAXSIZE)
	{
		s->push(i, 0);
		i++;
	}
	s->print();
	i = 0;
	while (i < MAXSIZE)
	{
		s->push(i, 1);
		i++;
	}
	s->print();
	i = 0;
	while (i < MAXSIZE)
	{
		s->push(i, 2);
		i++;
	}
	s->print();
	i = 0;
	while (i < 4)
	{
		s->pop(1);
		s->pop(2);
		s->pop(0);
		i++;
	}
	s->print();
	return (0);
}
