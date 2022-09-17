#include<stdio.h>

void menu();

int main()
{
    //printf("hello");

    int data[100],ch, qSize, fr = 0, re = 0;
    int vCount = 0;
    printf("enter queue size: ");
    scanf("%d",&qSize);

    menu();
    printf("enter choice: ");
    scanf("%d",&ch);

    while(ch != 0)
    {
        if(ch == 1)
        {
            if(vCount == qSize)
                printf("queue full\n\n");
            else
            {
                printf("enter value: ");
                scanf("%d",&data[re]);
                re = (re+1)%qSize;
                vCount++;
            }
        }
        else if(ch == 2)
        {
            if(vCount == 0)
                printf("queue empty\n\n");
            else
            {
                printf("%d dequeued\n\n",data[fr]);
                fr = (fr+1)%qSize;
                vCount--;
            }
        }
        else if(ch == 3)
        {
            printf("queue size: %d\n\n",vCount);
        }
        else if(ch == 4)
        {
            printf("front element: %d\n\n",data[fr]);
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
    printf("1. enqueue\n");
    printf("2. deququq\n");
    printf("3. queue size\n");
    printf("4. front element\n");
    printf("0. exit\n");
}

