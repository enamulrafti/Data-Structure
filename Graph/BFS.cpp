#include<stdio.h>
int data[100],vCount=0, qSize=0, fr = 0, re = 0;
struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node node;


node* createNode(int val);
int listSize(node *head);
node* insert_head(node *head, node *nn);
node* insert_tail(node *head, node *nn);
void listPrint(node *head);
void listPrint1(node *head);
void enqueue_data(int val);
void dequeue_data();
int front_element();
int check_existence(int visited[],int now, int c);


int main()
{
    int n;
    printf("n?");
    scanf("%d",&n);
    int graph[n][n]= {0};
    for(int row=0; row<n; row++)
    {
        for(int col=row+1; col<n; col++)
        {
            printf("%c-%c:",row+65,col+65);
            scanf("%d",&graph[row][col]);
            graph[col][row]=graph[row][col];
        }
    }
    int visited[n];
    qSize=25;
    node *nn,*head;
    node *head_arr[n];
    for(int i=0; i<n; i++)
    {
        nn=createNode(i);
        head_arr[i]=nn;
    }
    for(int row=0; row<n; row++)
    {
        for(int col=0; col<n; col++)
        {
            if(graph[row][col]==1)
            {
                nn=createNode(col);
                head_arr[row]=insert_tail(head_arr[row],nn);
            }
        }
    }
    node *temp_head_arr=head_arr[n];
    printf("Graph matrix:\n");
    for(int row=0; row<n; row++)
    {
        for(int col=0; col<n; col++)
        {
            printf("%d ",graph[row][col]);
        }
        printf("\n");
    }
    printf("Adjacent list:\n");
    for(int row=0; row<n; row++)
    {
        listPrint(head_arr[row]);

    }
    node *q, *temp;
    printf("Start node(Uppercase)?");
    char ch;
    fflush(stdin);
    scanf("%c",&ch);
    int start=ch-65;

    visited[0]=start;

    temp=head_arr[start]->next;
    while(temp!=NULL)
    {
        enqueue_data(temp->data);
        temp=temp->next;
    }

    int now,i=1;
    while(vCount!=0)
    {
        now= front_element();
        int check= check_existence(visited,now,i);
        if(check==0)
        {
            visited[i]=now;
            i++;
            dequeue_data();

            temp=head_arr[now]->next;
            while(temp!=NULL)
            {
                enqueue_data(temp->data);
                temp=temp->next;
            }
        }
        else
        {
            dequeue_data();
        }

    }

    printf("BFS: ");
    for(i=0; i<n; i++)
    {
        printf("%c ",visited[i]+65);
    }



    return 0;
}
int check_existence(int visited[],int now, int c)
{
    for(int i=0; i<c; i++)
    {
        if(visited[i]==now)
        {
            return 1;
        }
    }
    return 0;
}
node* createNode(int val)
{
    node *nn = new node();
    nn->data= val;
    nn->next = NULL;
    return nn;
}

node* insert_head(node *head, node *nn)
{
    if(head != NULL)
    {
        nn->next = head;
    }
    head = nn;
    return head;
}

int listSize(node *head)
{
    node *temp;
    temp = head;
    int counter = 0;
    while(temp != NULL)
    {
        counter++;
        temp = temp->next;
    }
    return counter;
}
void listPrint(node *head)
{
    node *temp;
    temp = head;
    while(temp != NULL)
    {
        printf("%c ",temp->data+65);
        temp = temp->next;
    }
    printf("\n");
}
void listPrint1(node *head)
{
    node *temp;
    temp = head;
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
node* insert_tail(node *head, node *nn)
{
    if(head == NULL)
    {
        head = insert_head(head, nn);
    }
    else
    {
        node *temp = head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = nn;
    }

    return head;
}
node* delete_head(node *head)
{
    head=head->next;
    return head;
}

void enqueue_data(int val)
{
    if(vCount==qSize)
    {
        printf("Queue Full\n\n");
    }
    else
    {

        data[re]=val;
        re = (re+1)%qSize;
    }
    vCount++;

}
void dequeue_data()
{
    if(vCount == 0)
        printf("queue empty\n\n");
    else
    {

        fr = (fr+1)%qSize;
    }
    vCount--;
}
int front_element()
{
    return data[fr];
}
