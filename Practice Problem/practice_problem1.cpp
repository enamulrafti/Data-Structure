#include<stdio.h>

struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node node;


void menu();
node* createNode();
void listPrint(node *head);
int listSize(node *head);
node* insert_head(node *head, node *nn);
node* insert_tail(node *head, node *nn);
node* insert_nth(node *head, node *nn, int lSize, int pos);
node* delete_head(node *head);
node* delete_nth(node *head, int lSize, int pos);
node* delete_tail(node *head);
void mid_value(node *head);

int main()
{
    node *head = NULL, *nn, *temp;
    int ch;


    menu();
    printf("enter choice: ");
    scanf("%d",&ch);

    while(ch != 0)
    {
        if(ch == 1)
        {
            nn = createNode();
            head = insert_head(head, nn);
        }
        else if(ch == 2)
        {
            int lSize, pos;
            lSize = listSize(head);
            printf("enter position: ");
            scanf("%d",&pos);

            if(pos >= 1 && pos <= lSize+1)
            {
                nn = createNode();
                head = insert_nth(head, nn, lSize, pos);
            }
            else
            {
                printf("invalid position\n\n");
            }
        }
        else if(ch == 3)
        {
            nn = createNode();
            head = insert_tail(head, nn);
        }
        else if(ch == 4)
        {
            head = delete_head(head);
        }
        else if(ch == 5)
        {
            int lSize, pos;
            lSize = listSize(head);
            printf("enter position: ");
            scanf("%d",&pos);

            if(pos >= 1 && pos <= lSize)
            {
                head = delete_nth(head, lSize, pos);
            }
            else
            {
                printf("invalid position\n\n");
            }
        }
        else if(ch == 6)
        {
            head = delete_tail(head);
        }
        else if(ch == 8)
        {
            listPrint(head);
        }
        else if(ch == 9)
        {
            printf("list size: %d\n\n",listSize(head));
        }
        else if(ch==10){
            int n;
            printf("n?");
            scanf("%d",&n);
            for(int i=0;i<n;i++){
                nn=createNode();
                head=insert_tail(head,nn);
            }
            mid_value(head);
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
    printf("1. insert(head)\n");
    printf("2. insert(nth)\n");
    printf("3. insert(tail)\n");
    printf("4. delete(head)\n");
    printf("5. delete(nth)\n");
    printf("6. delete(tail)\n");
    printf("8. print list\n");
    printf("9. list size\n");
    printf("10. Middle Value of list\n");
    printf("0. exit\n");
}

node* createNode()
{
    node *nn = new node();
    printf("enter value: ");
    scanf("%d",&nn->data);
    nn->next = NULL;
    return nn;
    /*
    node *nn = new node();
    printf("enter value: ");
    scanf("%d",&nn->data);
    nn->next = NULL;
    return nn; */
}
void mid_value(node *head){
    node *temp=head;
    int c=listSize(head);
    int len=c/2;
    printf("len: %d\n",len);
    listPrint(temp);
    for(int i=0;i<c;i++){
        if(i==len-1){
            printf("Mid value: %d\n\n",temp->data);
            break;
        }
        temp=temp->next;
    }
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

void listPrint(node *head)
{
    node *temp;
    temp = head;
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n\n");
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
