#include<stdio.h>
struct Node
{
    int data;
    struct Node *left, *right;
};
typedef struct Node node;

int selectOption();
node* insert_BST(node *temp, node *nn);
void inorder(node* root);
void preorder(node* root);
void postorder(node* root);
node* search_BST(node *temp, int n);
node* del(node *root,int key);
node *min_node(node *root);
int bst_tree(node *temp, int arr[], int index);
int min_find(int a[],int len);
void sp_inorder(node* root,int a);

int main()
{
    node *root = NULL, *nn;
    int ch, n, s=0;
    ch = selectOption();
    while(ch != 0)
    {
        if(ch == 1)
        {
            nn = new node();
            nn->left = NULL;
            nn->right = NULL;
            printf("enter value: ");
            scanf("%d",&nn->data);
            s++;
            root = insert_BST(root, nn);
        }
        else if(ch == 2)
        {
            printf("key?");
            int K;
            scanf("%d",&K);
            root= del(root,K);

        }
        else if(ch == 3)
        {
            printf("enter value to search: ");
            scanf("%d",&n);
            if(search_BST(root, n) == NULL)
            {
                printf("not found\n\n");
            }
            else
            {
                printf("found\n\n");
            }
        }
        else if(ch == 4)
        {
            inorder(root);
            printf("\n\n");
        }
        else if(ch == 5)
        {
            preorder(root);
            printf("\n\n");
        }
        else if(ch == 6)
        {
            postorder(root);
            printf("\n\n");
        }
        else if(ch== 7){
            int n;
            printf("n?");
            scanf("%d",&n);
            int arr[s];
            int c=bst_tree(root,arr,0);
            printf("c: %d\n",c);
            for(int j=0;j<c;j++){
                printf("%d ",arr[j]);
            }
            printf("\n");
            int minimum = min_find(arr,c);
            for(int i=0;i<c;i++){

                if(arr[i]%n==0){
                    printf("deleting...%d\n",arr[i]);
                    root=del(root,arr[i]);
                    printf("%d deleted\n",arr[i]);
                }
            }
            printf("\n");

            sp_inorder(root,minimum);
        }
        else
        {
            printf("invalid choice.\n\n");
        }
        ch = selectOption();
    }

}

int selectOption()
{
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Search\n");
    printf("4. Inorder\n");
    printf("5. Preorder\n");
    printf("6. Postorder\n");
    printf("7. BST->ARRAY\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");
    int ch;
    scanf("%d",&ch);
    return ch;
}
int min_find(int a[],int len){
    int m=a[0];
    for(int i=1;i<len;i++){
        if(m>a[i]){
            m=a[i];
        }
    }
    return m;
}
int bst_tree(node *temp, int arr[], int i){
    if(temp== NULL){
        return i;
    }
    arr[i]=temp->data;
    i++;
    if(temp->left!=NULL){
        i=bst_tree(temp->left,arr,i);
    }
    if(temp->right!=NULL){
        i=bst_tree(temp->right,arr,i);
    }
    return i;
}
node* del(node *root,int key)
{
	int a;
	node *current;
	current=root;
	if(root==NULL)
	{
		return root;
	}
	else if(key<root->data)
	{
		root->left=del(root->left,key);
	}
	else if(key>root->data)
	{
		root->right=del(root->right,key);
	}
	else
	{
		if(root->left==NULL)
		{
			node *temp=root->right;
			return temp;
		}
		else if(root->right==NULL)
		{
			node *temp=root->left;
			return temp;
		}
		node *temp;
		temp=min_node(root->right);
		root->data=temp->data;
		root->right=del(root->right,temp->data);
	}
	return root;
}
node *min_node(node *root)
{
	node *current;
	current=root;
	while(current->left!=NULL)
	{
		current=current->left;
	}
	return current;
}

node* insert_BST(node *temp, node *nn)
{
    if(temp == NULL)
    {
        return nn;
    }
    else if(nn->data < temp->data)
    {
        temp->left = insert_BST(temp->left, nn);
    }
    else
    {
        temp->right = insert_BST(temp->right, nn);
    }
}
void sp_inorder(node* root,int a)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d ",root->data-a);
        inorder(root->right);
    }
}
void inorder(node* root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void preorder(node* root)
{
    if(root != NULL)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(node* root)
{
    if(root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

node* search_BST(node *temp, int n)
{
    if(temp == NULL || temp->data == n)
    {
        return temp;
    }
    else if(n < temp->data)
    {
        temp = search_BST(temp->left, n);
    }
    else
    {
        temp = search_BST(temp->right, n);
    }
}
