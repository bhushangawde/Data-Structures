#include<stdio.h>
#include<conio.h>
#include<math.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

node *create(int);
void print( node *);
int elemax(node *);
void delete(node *);
void main()
{
    int choice,j,n,max;
    struct node *head , *P,*r;
    head =(node*)malloc(sizeof(node));
    head=NULL;
    for(j=0 ; j<5; j++)
    {
    printf("\n\nEnter your choice: \n1) Creating a list\n2) Deleting maximum element\n3) Returning maximum element\n4) Displaying list\n5) Quit \n");
    scanf("%d" ,&choice);
    switch(choice)
    {


         case 1 : head = create(n);
                break;

         case 2:delete(head);
                break;
	 case 3:
                 max = elemax(head);
                 printf("%d",max);
                 break;

         case 4: print(head);
                break;

         case 5 : break;

    }
    }
}


node *create(int n)
{
    int i;
    node *head1, *P , *q ;
     head1= (node*)malloc(sizeof(node));
      printf("Ënter the number of elements to be inserted: \n " );
    scanf("%d" , &n);

     printf("Enter the first number:\n");
     scanf("%d" , &head1->data);
     head1->next = NULL;
     q=head1;
     for( i=0; i<n-1 ; i++)
    {
        P= (node*)malloc(sizeof(node));
        scanf("%d" , &P->data);
        if(P->data > head1->data)
        {
            P->next= head1;
            head1 =P;

        }

        else
        {
            while(q->next != NULL && P->data < q->next->data)
               q=q->next;
            P->next = q->next;
            q->next = P;
        }
        printf("The new order is: ");
        print(head1);

    }
return(head1);
}

void print( node *p)
{
    while(p!=NULL)
    {

        printf("%d" , p->data);
        p=p->next;
    }
}

int elemax(node *P)
{
    return(P->data);
}

void delete(node *q)
{
    node *p;
    p=q;
    q=q->next;
    p->next=NULL;
    free(p);
    print(q);
}
