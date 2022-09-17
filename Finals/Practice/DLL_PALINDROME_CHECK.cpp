#include<stdio.h>

struct Node
{
    int data;
    struct Node *next, *prev;
};
typedef struct Node node;


void menu();
node* createNode();
void listPrint(node *head);
void listPrintRev(node *head);
int listSize(node *head);
node* insert_head(node *head, node *nn);
node* insert_tail(node *head, node *nn);
node* insert_nth(node *head, node *nn, int lSize, int pos);
node* delete_head(node *head);
node* delete_nth(node *head, int lSize, int pos);
node* delete_tail(node *head);
int checkPalindrome(node *head);

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
        else if(ch == 10)
        {
            listPrintRev(head);
        }
        else if(ch==11){
            listPrint(head);
            listPrintRev(head);
            int check=checkPalindrome(head);

            if(check==0){
                printf("Palindrome\n\n");
            }
            else{
                printf("Not Palindrome\n\n");
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
    printf("1. insert(head)\n");
    printf("2. insert(nth)\n");
    printf("3. insert(tail)\n");
    printf("4. delete(head)\n");
    printf("5. delete(nth)\n");
    printf("6. delete(tail)\n");
    printf("8. print list\n");
    printf("9. list size\n");
    printf("10. print list (reverse)\n");
    printf("11. Palindrome Check\n");
    printf("0. exit\n");
}
int checkPalindrome(node *head){
    node *temp1=head;
    node *temp2=head;

    while(temp1->next!=NULL){
        temp1=temp1->next;
    }
    while(temp1->prev!=NULL && temp2->next!=NULL){
        if(temp1->prev->data != temp2->next->data){
            return 1;
        }
        temp1=temp1->prev;
        temp2=temp2->next;
    }
return 0;
}
node* createNode()
{
    node *nn = new node();
    printf("enter value: ");
    scanf("%d",&nn->data);
    nn->next = NULL;
    nn->prev = NULL;
    return nn;
}

node* insert_head(node *head, node *nn)
{
    if(head != NULL)
    {
        nn->next = head;
        head->prev = nn;
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

void listPrintRev(node *head)
{
    node *temp;
    temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->prev;
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
        nn->prev = temp;
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
        nn->prev = temp;
        nn->next = temp->next;
        temp->next->prev = nn;
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
        head->prev = NULL;
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
        del->next->prev = temp;
        delete(del);

    }
    return head;
}




