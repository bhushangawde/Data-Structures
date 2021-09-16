#include<stdio.h>

typedef struct dnode
{
    int data;
    struct dnode *next;
    struct dnode *prev;
}dnode;

dnode *create(int);
dnode *insert( dnode *, int);
dnode *delete(dnode *, int);
dnode *print(dnode *);

void main()
{
    dnode *head;
    int choice, n, key1,key2;
    head= (dnode*)malloc(sizeof(dnode));
    head->next = head->prev = NULL;
    while(choice!=5)
    {
    printf("\n\nEnter the choice: \n1) CREATE the list \n2) INSERT an element \n3) DELETE an element \n4) PRINT the list \n5) QUIT\n ");

    scanf("%d", &choice);
    switch(choice)
    {
        case 1:printf("Enter the number of elements to be inserted : ");
              scanf("%d" , &n);
            head= create(n);
               break;

        case 2: printf("Enter the position where you want to insert your number : ");
                scanf("%d" , &key1);
                head= insert(head, key1);
                break;
        case 3: printf("Enter the position from where you want to delete the element");
                scanf("%d", &key2);
                head= delete(head,key2);
                break;

        case 4: printf("The list is:");
                head = print(head);
                break;

        case 5: break;

    }

    }
}

dnode *create( int n)
{

    dnode *head1;
    head1=(dnode*)malloc(sizeof(dnode));
    head1->next = head1->prev = NULL;
    int i;
    dnode *P, *q;
    printf("Enter the first element : ");
    scanf("%d" , &head1->data);

    for(i=0; i<n-1 ;i++)
    {
        P=(dnode*)malloc(sizeof(dnode));
        P->next =NULL;
        P->prev=NULL;
        printf("Enter the next element: ");
        scanf("%d" , &P->data);
        if(head1->next == NULL)
        {
            head1->next=P;
            P->prev = head1;

        }
        else
        {
            q=head1;
            while(q->next!=NULL)
            {
                q=q->next;
            }
            q->next=P;
            P->prev=q;
        }
        q=q->next;

    }
printf("The list is: ");
print(head1);
return(head1);

}

dnode *insert(dnode *head2 ,int key1)
{
    int i;
    dnode *p, *q;
    p=(dnode*)malloc(sizeof(dnode));
    p->next =NULL;
    p->prev=NULL;
    printf("Enter the element to be inserted: " );
    scanf("%d" , &p->data);
    /*if(head2==NULL)
    {
        head2=p;
    }*/
    if(head2!=NULL)
    {
    if(key1==1)
    {
        p->next=head2;
        head2->prev=p;
        head2=p;
    }
    else
    {
        q=head2;
    for(i=0;i<key1 ;i++)
    {
        q=q->next;
    }
    if(q==NULL)
        printf("The list is overflowed!");
    else if(q->next==NULL)
    {
        q->next=p;
        p->prev=q;
    }
    else
    {
        p->next=q->next;
        q->next->prev=p;
        p->prev=q;
        q->next=p;
    }
    }
    }
    printf("The list is : ", print(head2));

    return (head2);
}

dnode *print(dnode *q)
{

    while(q!=NULL)
    {
        printf("%d" , q->data);
        q=q->next;
    }

}

dnode *delete(dnode *head3 , int key2)
{
    int i;
    dnode *q,*r;
    int j;
    q=head3;
    if(key2==1)
    {
        r=head3;

        head3=head3->next;
        head3->prev=NULL;
         free(r);
    }
    else
    {
        for(i=0;i<key2;i++)
        {
            q=q->next;
        }
        if(q==NULL)
            printf("No element present at this location");
        else if(q->next==NULL)
        {
            q->prev->next=NULL;
            free(q);
        }
        else
        {
            r=q->next;
            q->next->next=q->next;
            r->next->prev=q;
            r->next=r->prev=NULL;
            free(r);
        }

    }
printf("The list is:");

print(head3);
return(head3);
}
