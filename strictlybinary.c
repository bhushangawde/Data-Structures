#include<stdio.h>

typedef struct Bnode
{
    int data;
    struct Bnode *left;
    struct Bnode *right;
}Bnode;

int flag = 1;
void Bstrict(Bnode *);
void *preorder(Bnode *);
Bnode *create();
Bnode *insert( Bnode *, int );

void main()
{

    Bnode *root;
    printf("\nYou have to create a binary search tree\n");
    root = create();
    printf("\nNow the binary search tree has been successfully created.\n");
    printf("\nNow check whether the formed binary tree is strictly binary or not");
    Bstrict(root);
    printf("\nThe value of the flag is %d  " , flag );
    if(flag==1)
    {
        printf("\nThe given tree is a strictly binary tree.\n");
    }

    if(flag==0)
    {
        printf("\nThe given tree is not a strictly binary tree.\n");
    }
}
Bnode *create()
{
    int x,i,n;
    Bnode *root1;
    root1=NULL;
    printf("\nEnter the number of elements to be inserted in the tree:\n");
    scanf("%d" , &n);
    printf("\nEnter the values to be inserted in  the tree\n");

    for( i =0; i<n ; i++)
    {
        scanf("%d" , &x);
        root1 = insert(root1,x);
    }
    printf("\n\nPREORDER :\n");
    preorder(root1);
    return(root1);
}

Bnode *insert( Bnode *T , int y)
{
Bnode *q,*p,*r;
r=(Bnode*)malloc(sizeof(Bnode));
r->data = y;
r->left = r->right = NULL;
if(T==NULL)
{
    return(r);
}
p=T;

while(p!=NULL)
{
    q=p;
    if(y>p->data)
    {
    p=p->right;
    }
    else if (y<p->data)
    {
    p=p->left;
    }
}

if(y<q->data)
{
q->left = r;
}
else if(y>q->data)
{
q->right= r;

}
return(T);

}

void *preorder(Bnode *T)
{
if(T!=NULL)
{
printf("%d", T->data);
preorder(T->left);
preorder(T->right);

}
}

 void Bstrict(Bnode *T)
{
    if(T==NULL)
        return;

        if(T->left !=NULL && T->right ==NULL)
        {
            flag = 0;
            return;
        }
        if (T->right!=NULL && T->left == NULL)
        {
            flag = 0;
            return;
        }
   Bstrict(T->left);
   Bstrict(T->right);
}


