#include<stdio.h>

void menu();
int push(int data[], int top);
int pop(int data[],int top);
int array_size(int data[]);

int main()
{
    //printf("hello");

    int data[100],ch, stSize=0, top=0;
    printf("enter stack size: ");
    scanf("%d",&stSize);

    menu();
    printf("enter choice: ");
    scanf("%d",&ch);

    while(ch != 0)
    {
        if(ch == 1)
        {
            top= push(data,top);
            stSize= array_size(data);
        }
        else if(ch == 2)
        {
            top= pop(data,top);
            stSize= array_size(data);
        }
        else if(ch == 3)
        {
            int a = array_size(data);
            printf("stack size: %d\n\n",a);
        }
        else if(ch == 4)
        {
            if(array_size(data)==0)
            {
                printf("Empty Stack\n\n");
            }
            else
            {
                printf("top element: %d\n\n",data[top-1]);
            }

        }
        else
        {
            printf("invalid choice\n\n");
        }
        menu();
        printf("enter choice: ");
        scanf("%d",&ch);
    }
}
int push(int data[], int top)
{
    if(array_size(data) == top)
    {
        printf("stack full\n\n");
    }
    else
    {
        printf("enter value: ");
        scanf("%d",&data[top]);
        top++;
    }
    return top;
}
int pop(int data[],int top)
{
    if(top == 0)
    {
        printf("stack empty\n\n");
    }
    else
    {
        top--;
        printf("%d deleted\n",data[top]);
    }
    return top;
}
int array_size(int data[])
{
    int len=sizeof data/sizeof data[0];
    printf("Len: %d\n",len);
    return len;
}

void menu()
{
    printf("1. push\n");
    printf("2. pop\n");
    printf("3. stack size\n");
    printf("4. top element\n");
    printf("0. exit\n");
}
