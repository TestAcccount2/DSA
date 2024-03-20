#include<stdio.h>
#include<math.h>
#define max 5
int stack_list[max],top=-1;
void push(int m)
{
if(top==max-1)
printf("Stack overflow\n");
else
{
top++;
stack_list[top]=m;
}
}
int pop()
{
if(top==-1)
{
printf("Stack underflow\n");
return -1;
}
else
return stack_list[top--];
}
void display()
{
int i;
if(top==-1)
printf("Stack is empty\n");
else
{
printf("\n The elements are\n");
for(i=top;i>=0;i--)
printf("%d\n",stack_list[i]);
}
}
void palindrome() {
    int n, rem, i;
    printf("\nEnter n: ");
    scanf("%d", &n);
    top = -1; 
    while (n != 0) {
        rem = n % 10;
        push(rem);
        n = n/10;
    }
    for (i = 0; i <= top / 2; i++) {
        if (stack[i] != stack[top - i]) {
            printf("\nIt is not a palindrome\n");
            return;
        }
    }
    printf("\nIt is a palindrome\n");
}
int main()
{
int c,m;
while(1)
{
printf("\n Enter \n1-push \n2-pop \n3-display \n4-palindrome \n");
scanf("%d",&c);
switch(c)
{
case 1: printf("\n Enter an element\t");
scanf("%d",&m);
push(m);
break;
case 2:m=pop();
if(m!=-1)
printf("\n The popped elementis %d",m);
break;
case 3: display();
break;
case 4: palindrome();
break;
default:return 0;
}
}
}
