#include<iostream>
#include<stdlib.h>
//#include<conio>
using namespace std;
void dfsVisit(struct lnode *head,int &);
struct lnode
{
   int vno;
   char colour;
   short d,time,fin;
   struct AdjList *nextEdge;
};
struct AdjList
{
   struct lnode *nPtr;
   struct AdjList *lPtr;
};

struct graph
{
   int vertice;
   struct lnode **arr;
};

struct lnode* getnode(int vno)
{
   struct lnode *newnode=(struct lnode*)malloc(sizeof(struct lnode));
   newnode->nextEdge=NULL;
   newnode->vno=vno;
   return newnode;
}

struct graph* getgraph(int vertice)
{
   struct graph *newgraph=(struct graph*)malloc(sizeof(struct graph));
   newgraph->vertice=vertice;
   newgraph->arr=(struct lnode**)malloc(vertice*sizeof(struct lnode*));


   for(int i=0;i<vertice;i++)
      {
            newgraph->arr[i]=getnode(i);
      }
   return newgraph;
}

void addEdge(struct graph *graph,int source,int dest)   //directed graph
{  struct AdjList *temp=(struct AdjList *)malloc(sizeof(AdjList));
   temp->lPtr=graph->arr[source]->nextEdge;
   graph->arr[source]->nextEdge=temp;
   temp->nPtr=graph->arr[dest];
}

void printGraph(struct graph* graph)
{struct AdjList *temp;
    for(int i=0;i<graph->vertice;i++)
    {
        temp=graph->arr[i]->nextEdge;
        cout<<"head"<<i<<" ";
        while(temp)
        {
            cout<<"->"<<temp->nPtr->vno;
            temp=temp->lPtr;
        }
      cout<<endl;
    }
}



void depthFirstSearch(struct graph *graph)
{int i=0;
 int time =0;
   for(i=0;i<graph->vertice;i++)
   {
      graph->arr[i]->colour='w';
      graph->arr[i]->d=0;
      graph->arr[i]->time=0;
   }
   int j=0;
   for(i=0;i<graph->vertice;i++)
   {
      if(graph->arr[i]->colour=='w')
        {
            dfsVisit(graph->arr[i],time);
        }

   }

}

void dfsVisit(struct lnode *nodePtr,int &time)
{

   nodePtr->d=++time;
   struct AdjList *listPtr=nodePtr->nextEdge;
   while(listPtr!=NULL)
   {

      if(listPtr->nPtr->colour=='w')
      {
         nodePtr->colour='g';
         dfsVisit(listPtr->nPtr,time);
      }
      listPtr=listPtr->lPtr;

   }
   nodePtr->colour='b';
   nodePtr->fin=++time;
}

void printDfs(struct graph* graph)
{
   for(int i=0;i<graph->vertice;i++)
    {
        cout<<graph->arr[i]->vno<<"\td:"<<graph->arr[i]->d<<"\tfin:"<<graph->arr[i]->fin<<endl;
    }
}

int main()
{
   int vertice,source,dest,choice;
   cout<<"Enter the no. of vertice: ";
   cin>>vertice;
   struct graph *graph=getgraph(vertice);
   do
    {
      cout<<"\n1.Add edge\n2.To print AdjList\n3.Depth first search\n4.Exit\nEnter your choice: ";
      cin>>choice;
      switch(choice)
      {
       case 1:cout<<"Enter the source and destination vertex to form an edge: ";
              cin>>source>>dest;
              addEdge(graph,source,dest);
              break;
       case 2:printGraph(graph);
              break;
       case 3:cout<<"dfs"<<endl;
              depthFirstSearch(graph);
              printDfs(graph);
              break;
      }
    }while(choice!=4);
}












