#include<stdio.h>
struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node node;


void menu();
node* createNode();
void listPrint(node *head, int top);
int listSize(node *head);
node* insert_head(node *head, node *nn);
node* insert_tail(node *head, node *nn);
node* insert_nth(node *head, node *nn, int lSize, int pos);
node* delete_head(node *head);
node* delete_nth(node *head, int lSize, int pos);
node* delete_tail(node *head);

int main()
{
    node *head = NULL, *nn, *temp;
    int ch,stSize,top=0;


    printf("Stack Size?");
    scanf("%d",&stSize);

    menu();
    printf("enter choice: ");
    scanf("%d",&ch);

    while(ch != 0)
    {
        if(ch == 1)
        {
            if(stSize==top){
                printf("Stack is full.\n\n");
            }
            else{
                nn=createNode();
                if(head==NULL){
                    head=insert_head(head,nn);
                }else{
                    head=insert_tail(head,nn);
                }
                top++;
            }
        }
        else if(ch == 2)
        {
            if(top==0){
                printf("Stack is Empty!\n\n");
            }
            else{
                head=delete_tail(head);
                top--;
            }
        }
        else if(ch == 3)
        {
            printf("Stack Size: %d\n\n",top);
        }
        else if(ch == 4)
        {
            if(top==0){
                printf("Empty Stack!\n\n");
            }
            else{
                listPrint(head,top);
            }
        }
        else
        {
            printf("wrong input.\n\n");
        }
        menu();
        printf("enter choice: ");
        scanf("%d",&ch);
    }

}

void menu()
{
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Stack Size\n");
    printf("4. Top Element\n");
    printf("0. exit\n");
}

node* createNode()
{
    node *nn = new node();
    printf("enter value: ");
    scanf("%d",&nn->data);
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

void listPrint(node *head, int top)
{
    node *temp;
    temp = head;
    int c=0;
    while(temp != NULL)
    {
        c++;
        if(c==top){
            printf("Top data: %d \n\n",temp->data);
        }

        temp = temp->next;
    }
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

node* insert_nth(node *head, node *nn, int lSize, int pos)
{
    node *temp;
    temp = head;
    if(pos == 1)
    {
        head = insert_head(head, nn);
    }
    else if(pos == lSize+1)
    {
        head = insert_tail(head, nn);
    }
    else
    {
        int i;

        for(i = 1; i <= pos-2; i++)
        {
            temp = temp->next;
        }
        nn->next = temp->next;
        temp->next = nn;
    }

    return head;
}

node* delete_head(node *head)
{
    if(head == NULL)
    {
        printf("nothing to delete\n\n");
    }
    else
    {
        node *temp;
        temp = head;
        printf("%d poped\n\n",temp->data);
        head = head->next;

        delete(temp);
    }

    return head;
}

node* delete_tail(node *head)
{
    int lSize;
    lSize = listSize(head);

    if(lSize <= 1)
    {
        head = delete_head(head);
    }
    else
    {
        int i;
        node *temp;
        temp = head;

        for(i = 1; i <= lSize-2; i++)
        {
            temp = temp->next;
        }
        printf("%d poped\n\n",temp->next->data);
        delete(temp->next);
        temp->next = NULL;
    }
    return head;
}

node* delete_nth(node *head, int lSize, int pos)
{
    if(pos == 1)
    {
        head = delete_head(head);
    }
    else if(pos == lSize)
    {
        head = delete_tail(head);
    }
    else
    {
        node *temp, *del;
        temp = head;
        int i;

        for(i = 1; i <= pos-2; i++)
        {
            temp = temp->next;
        }
        del = temp->next;
        temp->next = del->next;
        delete(del);

    }
    return head;
}

