#include<stdio.h>
void menu();
int enqueue(int data[],int qSize,int vCount);
void vcount_print(int vCount);
int dequeue_data(int data[],int qSize,int vCount,int fr);
void  front_element(int data[],int fr);
int main()
{
    int data[100],ch, qSize, fr = 0, re = 0;
    int vCount = 0;
    printf("Size?");
    scanf("%d",&qSize);

    menu();
    printf("Choice?");
    scanf("%d",&ch);

    while(ch != 0)
    {
        if(ch==1)
        {
            re=enqueue_data(data,qSize,vCount,re);
            vCount++;
        }
        else if(ch==2)
        {
            fr=dequeue_data(data,qSize,vCount,fr);
            vCount--;
        }
        else if(ch==3){
            vcount_print(vCount);
        }
        else if(ch==4){
            front_element(data,fr);
        }
        else{
            printf("Invalid Choice!!\n\n");
        }

        menu();
        printf("Choice?");
        scanf("%d",&ch);
    }
    return 0;
}
void  front_element(int data[],int fr){
    printf("Front Element: %d\n\n",data[fr]);

}
void vcount_print(int vCount){
    printf("Queue Size: %d\n\n",vCount);
}

int enqueue_data(int data[],int qSize,int vCount,int re)
{
    if(vCount==qSize)
    {
        printf("Queue Full\n\n");
    }
    else
    {
        printf("value?");
        scanf("%d",&data[re]);
        re = (re+1)%qSize;
    }
    return re;
}
int dequeue_data(int data[],int qSize,int vCount,int fr)
{
    if(vCount == 0)
        printf("queue empty\n\n");
    else
    {
        printf("%d dequeued\n\n",data[fr]);
        fr = (fr+1)%qSize;
    }
    return fr;
}
void menu()
{
    printf("1. Enqueue\n");
    printf("2. Dequeqe\n");
    printf("3. Queue size\n");
    printf("4. Front element\n");
    printf("0. Exit\n");
}
