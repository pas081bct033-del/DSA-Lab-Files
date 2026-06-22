#include<iostream>
#define MAX 5
using namespace std;
int stack[MAX];
int top=-1;
void push(int value)
{
	if(top==MAX-1)
	{
		cout<<"Stack overflow"<<endl;
	}
	else
	{
		top++;
		stack[top]=value;
		cout<<value<<" is pushed into stack"<<endl;
	}
}
void pop()
{
	if(top==-1)
	{
		cout<<"Stack underflow"<<endl;
	}
	else
	{
		
		cout<<stack[top]<<" is poped from stack"<<endl;
		top--;
	}
}
void display()
{
	if(top==-1)
	{
		cout<<"Stack empty"<<endl;
	}
	else
	{
	cout<<"Stack Element:"<<endl;
	for(int i=top;i>=0;i--)
	{
		cout<<stack[i]<<endl;
	}
}
}
int main()
{
	push(10);
	push(20);
	push(25);
	display();
	pop();
	display();
	return 0;
}
