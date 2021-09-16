#include<stdio.h>

typedef struct Bnode
{
    int data;
    struct Bnode *left;
    struct Bnode *right;
}Bnode;

void *preorder(Bnode *);
void *postorder(Bnode *);
void *inorder(Bnode *);
Bnode *create();
Bnode *insert( Bnode *, int );
Bnode *delete(Bnode *);

void main()
{

    Bnode *root;
    printf("\nYou have to create a binary search tree\n");
    root = create();
    printf("\nNow the binary search tree has been successfully created.\n");
    printf("\nNow your next task is to delete all the present leaf nodes from the binary search tree\n" );
    root=delete(root);
    preorder(root);

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
    printf("\n\nPOSTORDER:\n");
    postorder(root1);
    printf("\n\nINORDER:\n");
    inorder(root1);

    return(root1);
}

Bnode *insert( Bnode *T , int x)
{
Bnode *q,*p,*r;
r=(Bnode*)malloc(sizeof(Bnode));
r->data = x;
r->left = r->right = NULL;
if(T==NULL)
{
    return(r);
}
p=T;

while(p!=NULL)
{
    q=p;
    if(x>p->data)
    {
    p=p->right;
    }
    else if (x<p->data)
    {
    p=p->left;
    }
}

if(x<q->data)
{
q->left = r;
}
else if(x>q->data)
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
void *postorder(Bnode *T)
{
if(T!=NULL)
{

postorder(T->left);
postorder(T->right);
printf("%d", T->data);
}

}

void *inorder(Bnode *T)
{
    if(T!=NULL)
{

inorder(T->left);
printf("%d", T->data);
inorder(T->right);

}
}

Bnode *delete(Bnode *T)
{
    Bnode *root = T;
    Bnode *temp;
    if(T==NULL)
    {
        printf("\nThe tree is empty.\n");
        return(T);
    }

    if(T!=NULL)
    {

        if(T->left==NULL && T->right==NULL)
        {
            temp=T;
            free(temp);
            return (NULL);
        }
        else
            {
                T->left = delete(T->left);
                T->right = delete(T->right);
            }

    }

    return(T);

}
