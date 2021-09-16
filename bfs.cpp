#include<iostream>
using namespace std;
#define GRAY  1
#define BLACK  2
#define WHITE  0
#define INFINITY  10000000

struct Node
{
    struct Node *next;
    int vertex;
    int color;
    int d ;
    Node *pred;
};

struct Q
{
    int R,F;
    int data[20];
};


Node *A[20];
int n;
void nodes();
void makeGraph();
void insertNode(int,int);
int inDegree(int);
int outDegree(int);
void BFS();
void initialize(Q *);
void enqueue(Q * ,int);
int dequeue(Q*);
int isempty(Q*);


int main()
{
    int id,od,i;
    makeGraph();
    cout<<"\nNow compute the indegree and outdegree of the graph constructed:";
    for(i = 0;i<n;i++)
    {
        od = outDegree(i);
        id = inDegree(i);
        cout<<"\nNode: "<<i<<"   Indegree:"<<id<<"    Outdegree:"<<od;
    }
    cout<<"\nNow you have to implement BREADTH FIRST SEARCH GRAPH TRAVERSAL";
   BFS();
    return 0;
}

void makeGraph()
{
    int i,x,fv,sv;
    cout<<"Enter the number of vertices to be inserted in the graph:  ";
    cin>>n;
    for(i=0;i<n;i++)
    {
    A[i]=NULL;
    }

    nodes();
    cout<<"\nEnter the number of edges you want to insert:";
    cin>>x;
    for(i=0;i<x;i++)
    {
        cout<<"\nEnter an edge:";
        cin>>fv>>sv;
        insertNode(fv,sv);
    }
}

void nodes()
{
    int i ;
    for(i=0;i<n;i++)
    {
    Node *p;
    p=new Node ;
    p->next = NULL;
    p->vertex = i;
    A[i] = p;
    }
    cout<<"\nThe first elements have been added.";
}
void insertNode(int fv , int sv)
{
    Node *p,*q;
    p = new Node;
    p->next=NULL;

	 if(A[fv] !=NULL )
    {
        p->vertex = sv;
        q=A[fv];
        while(q->next!=NULL)
        {
            q=q->next;
        }
        q->next=p;
    }
}
 int outDegree(int iv)
 {
     int Od=0;
     Node *p;
     if(A[iv]==NULL)
     {
         Od=0;
     }
     else
     {
         p=A[iv];
         p=p->next;
         while(p!=NULL)
         {
         	Od++;
             p=p->next;

         }
     }
     return (Od);
 }

 int inDegree(int iv)
 {
     int i,Id=0;;
    Node *q;
    for(i=0; i<n ; i++)
    {
        q=A[i];
        q=q->next;
        while(q!=NULL)
        {
            if(q->vertex == iv)
            {
                Id++;
            }
            q=q->next;
        }
    }
    return (Id);
 }

void BFS()
{
    Q pq;
    int j,i,x,u;
    Node *p ,*q,*r,*s,*t;
    cout<<"\Enter the vertex which you want to select as the source vertex:";
    cin>>x;
    q=A[x];
    for(i=0 ; i<n; i++)
    {
	p=A[i];
    while (p!=NULL)
    {
			if(p->vertex!=x)
		{
            p->d = INFINITY;
            p->color = WHITE;
            p->pred = NULL;
		}
		  p = p->next;
    }
	}
        q->d=0;
        q->color = GRAY;
        cout<<"q->color"<<q->color;
        q->pred= NULL;

    initialize(&pq);
    enqueue(&pq , x);
    while(!isempty(&pq))
    {
        u = dequeue(&pq);
        s=r=A[u];
        r=r->next;
        while(r!=NULL)
        {
            if(r->color = WHITE)
            {
                r->color = GRAY ;
                r->d = r->d +1;
                r->pred = s ;
                enqueue(&pq , r->vertex);
            }
            r=r->next;
        }
        for(i=0;i<n;i++)
        {
           p=A[i];
            while(p!=NULL)
            {
            if(i==x)
            {
                s->color = BLACK;
                cout<<"\ns->color= "<<s->color;
            }
                   p=p->next;
            }
        }
    }
    cout<<"\nTo check whether the graph has been traversed properly or not:";
     for(j=0 ; j<n; j++)
    {
	t=A[j];
	t=t->next;
    while (t!=NULL)
    {
		cout<<"\nt->color = "<<t->color;
		t=t->next;
    }

}
}

void initialize(Q *P)
{
    P->F = -1;
    P->R = -1;
}

int isempty(Q *P)
{
    if(P->R==-1)
    {
        cout<<"\nThe  queue is empty.";
        return (1);
    }
    else
    {
    return (0);
	}
}

void enqueue(Q *P, int x)
{
    if(P->R == -1)
    {
        P->R=P->F = 0;
        P->data[P->R] = x;
    }
    else
    {
        P->R=P->R+ 1;
        P->data[P->R] = x;
    }

}

int  dequeue(Q *P)
{
    int y;
    if(P->R == -1)
    {
        cout<<"\n The queue is empty.";
    }

    else if (P->R==P->F)
    {
        y=P->data[P->F];
        P->R=-1;
        P->F=-1;
    }
    else
    {
        y=P->data[P->F];
        P->F=P->F+1;
    }
    return y;
}

