#include "stack.h"

stack::stack(){
	top = -1;
}
void stack::push(int x){
	top = top + 1;
	array[top] = x;
}
int stack::pop(){
	int u = top;
	top = top - 1;
	return array[u];
}
bool isnum(char y){
	if (y == '0' || y == '1' || y == '2' || y == '3' || y == '4' || y == '5' || y == '6' || y == '7' || y == '8' || y == '9')
		return true;
	else
		return false;
}
int sum(int j,int k,int &l){
	int f = j + k + l;
	if (f >= 10){
		f = f - 10;
		l = 1;
	} else
		l = 0;
	return f;
}
int diff(int b,int n,int &m){
	b = b + m;
	if (b < n){
		b = b + 10;
		m = -1;
	} else
		m = 0;
	int g = b - n;
	return g;
}

