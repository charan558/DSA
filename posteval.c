#include<stdio.h>
#define M 10
int stack[M],top=-1;
void push(int);
int pop();
int main()
{
	char po_exp[10];
	int res;
	printf("ENTER POSTFIX EXPRESSION\n");
	scanf("%s",po_exp);
	res=postfix_evaluation(po_exp);
	printf("RESULT=%d \t",res);

}
int postfix_evaluation(char po_exp[])
{
	int a,b,result,i;
	for(i=0;po_exp[i]!='\0';i++)
	{
		if(isdigit(po_exp[i]))
		push(po_exp[i]-'0');
		else
		{
			a=pop();
			b=pop();
			switch(po_exp[i])
			{
				case '+':result=b+a;
					break;
				case '-':result=b-a;
					break;
				case '*':result=b*a;
					break;
				case '/':result=b/a;
					break;
			}
			push(result);
		}
	}
	return pop();
}
void push(int element)
{
	if(top>=M-1)
	{
		printf("STACK IS FULL\n");
		return;
	}
	stack[++top]=element;
}
int pop()
{
	if(top<0)
	{
		printf("STACK UNDERFLOW\n");
		return 0;
		
	}
	return stack[top--];
}
	
	
	
