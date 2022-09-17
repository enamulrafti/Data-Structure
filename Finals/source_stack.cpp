#include<stdio.h>

void menu();

int main()
{
    //printf("hello");

    int data[100],ch, stSize, top=0;
    printf("enter stack size: ");
    scanf("%d",&stSize);

    menu();
    printf("enter choice: ");
    scanf("%d",&ch);

    while(ch != 0)
    {
        if(ch == 1)
        {
            if(stSize == top)
                printf("stack full\n\n");
            else
            {
                printf("enter value: ");
                scanf("%d",&data[top]);
                top++;
            }
        }
        else if(ch == 2)
        {
            if(top == 0)
                printf("stack empty\n\n");
            else
            {
                top--;
                printf("%d deleted\n",data[top]);
            }
        }
        else if(ch == 3)
        {
            printf("stack size: %d\n\n",top);
        }
        else if(ch == 4)
        {
            printf("top element: %d\n\n",data[top-1]);
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


void menu()
{
    printf("1. push\n");
    printf("2. pop\n");
    printf("3. stack size\n");
    printf("4. top element\n");
    printf("0. exit\n");
}
