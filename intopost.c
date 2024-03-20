#include<stdio.h>
#include<ctype.h>
char stk[100];
int tos = -1;
void push(char opr)
{
stk[++tos] = opr;
}
char pop()
{
return(stk[tos--]);
}
int preced(char opr)
{
if(opr=='^'||opr=='%') return(4);
if(opr=='*'||opr=='/') return(3);
if(opr=='+'||opr=='-') return(2);
if(opr=='('||opr=='#') return(1);
}
void main()
{
char infix[20],postfix[20];
int i,j=0;
printf("\nEnter valid INFIX expression\n");
scanf("%s",infix);
push('#');
for(i=0; infix[i]!='\0'; i++)
{
if(infix[i]=='(')
push('(');
else if(isalnum(infix[i]))
postfix[j++] = infix[i];
else if(infix[i]==')')
{
while(stk[tos] != '(')
postfix[j++] = pop();
pop();
}
else
{
while(preced(stk[tos]) >= preced(infix[i]))
postfix[j++] = pop();
push(infix[i]);
}
}
while(stk[tos] != '#')
postfix[j++] = pop();
postfix[j]='\0';
printf("\n INFIX EXPRESSION = %s",infix);
printf("\n POSTFIX EXPRESSION = %s",postfix);
getchar();
}
