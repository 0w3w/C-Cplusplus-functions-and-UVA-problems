#define MAXSIZE 	10
#define NUMSTACKS 3

class 						Stacks
{
	public:
		int 						myStacks[MAXSIZE * NUMSTACKS];
		int 						topStacks[NUMSTACKS];

		Stacks();
		~Stacks();
		void push(int value, int numStack);
		int pop(int numStack);
		int peek(int numStack);
		void print();
};
