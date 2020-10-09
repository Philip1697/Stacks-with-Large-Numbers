#include <iostream>
using namespace std;
#include "stack.h"

int main(int argc,char **argv) {
	int c = 1;
	char C;
	int c1 = 0;
	int c2 = 0;
	int c3 = 0;
	stack s1,s2,s3,s4,so,sr;
	for (int i = 0;argv[1][i] != '\0';i++){
		if (argv[1][i] == '+' || argv[1][i] == '-'){
			C = argv[1][i];
			if (c == 1)
				c = c + 5;
			else
				c = c + 3;
		} else if (argv[1][i] == '.'){
			c = c + 2;
			c3 = c3 + 1;
		}
		else if (isnum(argv[1][i]) && c == 1){
			int z = argv[1][i] - '0';
			s1.push(z);
		} else if (isnum(argv[1][i]) && c == 3){
			int z = argv[1][i] - '0';
			s2.push(z);
			c1 = 1;
		} else if (isnum(argv[1][i]) && c == 6){
			int z = argv[1][i] - '0';
			s3.push(z);
		} else if (isnum(argv[1][i]) && c == 8){
			int z = argv[1][i] - '0';
			s4.push(z);
			c2 = 1;
		} else {
			cout << "Invalid input";
			return 0;
		}
	}
	if ((c3 == 1 && s2.top == -1 && s4.top == -1) || (c3 == 2 && (s2.top == -1 || s4.top == -1)) || (s1.top == -1) || (s3.top == -1)){
		cout << "Invalid input";
		return 0;
	}
	int cds = 0;
	int cdd = 0;
	if (c1 == 1 && c2 == 1){
		if (s2.top == s4.top){
			for (int i = s2.top;i > -1;i--)
				if (C == '+')
					sr.push(sum(s2.pop(),s4.pop(),cds));
				else
					sr.push(diff(s2.pop(),s4.pop(),cdd));
		} else if (s2.top < s4.top){
			int q = s4.top - s2.top;
			for (int i = 0;i < q;i++)
				if (C == '+')
					sr.push(s4.pop());
				else
					sr.push(diff(0,s4.pop(),cdd));
			for (int i = s2.top;i > -1;i--)
				if (C == '+')
					sr.push(sum(s2.pop(),s4.pop(),cds));
				else
					sr.push(diff(s2.pop(),s4.pop(),cdd));
		} else if (s2.top > s4.top){
			int e = s2.top - s4.top;
			for (int i = 0;i < e;i++)
				sr.push(s2.pop());
			for (int i = s4.top;i > -1;i--)
				if (C == '+')
					sr.push(sum(s2.pop(),s4.pop(),cds));
				else
					sr.push(diff(s2.pop(),s4.pop(),cdd));
		}
	} else if (c1 == 1 && c2 == 0)
		for (int i = s2.top;i > -1;i--)
			sr.push(s2.pop());
	else if (c1 == 0 && c2 == 1){
		for (int i = s4.top;i > -1;i--)
			if (C == '+')
				sr.push(s4.pop());
			else
				sr.push(diff(0,s4.pop(),cdd));
	}
	int cs = cds;
	int cd = cdd;
	if (s1.top == s3.top){
		for (int i = s1.top;i > -1;i--)
			if (C == '+')
				so.push(sum(s1.pop(),s3.pop(),cs));
			else
				so.push(diff(s1.pop(),s3.pop(),cd));
	} else if (s1.top > s3.top){
		for (int i = s3.top;i > -1;i--)
			if (C == '+')
				so.push(sum(s1.pop(),s3.pop(),cs));
			else
				so.push(diff(s1.pop(),s3.pop(),cd));
		for (int i = s1.top;i > -1;i--)
			if (C == '+')
				so.push(sum(s1.pop(),0,cs));
			else
				so.push(diff(s1.pop(),0,cd));
	} else if (s1.top < s3.top){
		for (int i = s1.top;i > -1;i--)
			if (C == '+')
				so.push(sum(s1.pop(),s3.pop(),cs));
			else
				so.push(diff(s1.pop(),s3.pop(),cd));
		for (int i = s3.top;i > -1;i--)
			if (C == '+')
				so.push(sum(s3.pop(),0,cs));
			else
				so.push(diff(0,s3.pop(),cd));
	}
	if (cs == 1)
		so.push(cs);
	int h = 0;
	for (int i = so.top;i > -1;i--){
		int a = so.pop();
		if (a == 0 && h == 0){
			if (i == 0)
				cout << a;
		}
		else{
			cout << a;
			h = 1;
		}
	}
	if (c1 == 1 || c2 == 1){
		cout << ".";
		for (int i = sr.top;i > -1;i--)
			cout << sr.pop();
	}
	return 0;
}
