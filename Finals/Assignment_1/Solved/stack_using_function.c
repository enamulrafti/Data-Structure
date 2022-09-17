#include<stdio.h>

int push(int data[],int stSize,int top);
int pop(int data[],int stSize,int top);
void stack_size(int top);
void top_element(int data[],int top);

int main()
{

    int data[100],ch, stSize, top=0;
    printf("Size?");
    scanf("%d",&stSize);

    menu();
    printf("Choice?");
    scanf("%d",&ch);
    while(ch!=0)
    {
        if(ch==1)
        {
            top= push(data,stSize,top);

        }
        else if(ch==2)
        {
            top=pop(data,stSize,top);
        }
        else if(ch==3)
        {
            stack_size(top);
        }
        else if(ch==4)
        {
            top_element(data,top);
        }
        else
        {
            printf("Invalid Choice.\n\n");
        }

        menu();
        printf("Choice?");
        scanf("%d",&ch);
    }


    return 0;
}
void top_element(int data[],int top)
{
    if(top==0)
    {
        printf("Stack Is Empty!\n\n");
    }
    else
    {
        printf("Top Element: %d\n\n",data[top-1]);
    }

}
void stack_size(int top)
{
    printf("Stack Size: %d\n\n",top);
}
int pop(int data[],int stSize,int top)
{
    if(top==0)
    {
        printf("Stack Empty!\n\n");
    }
    else
    {
        top--;
        printf("%d Poped\n\n",data[top]);
    }

    return top;
}
int push(int data[],int stSize,int top)
{
    if(stSize==top)
    {
        printf("Stack Full!\n\n");
    }
    else
    {
        printf("Val?");
        scanf("%d",&data[top]);
        top++;
    }
    return top;
}
void menu()
{
    printf("1. push\n");
    printf("2. pop\n");
    printf("3. stack size\n");
    printf("4. top element\n");
    printf("0. exit\n");
}
