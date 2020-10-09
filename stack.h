#ifndef STACK_H_
#define STACK_H_

class stack{
public:
	stack();
	void push(int x);
	int pop();
	int array[1000];
	int top;
};
bool isnum(char y);
int sum(int j,int k,int &l);
int diff(int b,int n,int &m);

#endif /* STACK_H_ */
