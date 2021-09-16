#include<iostream>
#include<string.h>
#include<conio.h>
#define max 100
using namespace std;

class stack
{
private:
    int data[max];
    int top;
public:
    void initialise()
    {
        top= -1;
    }
    int empty()
    {
        if(top==-1)
        {
        cout<<"stack is empty";
        return 1;
        }
        else
        {
        return 0;
        }
    }

    int full()
    {
        if(top== max-1)
        {
        cout<<"stack is full";
        return 1;
        }
        else
        {
        return 0;
        }
    }
    int eletop()
    {
        return top;
    }
    void push( int x)
    {
        top= top +1;
        top=x;
    }

   int pop()
    {
        int y;
        y= top;
        top= top-1;
        return y;
    }

};
int precedence(char);
//void parmatch(stack,stack,char[]);
void infixtopostfix(char[],char[]);
int main()
{
    int i;
    char a[20],b[20];
    stack S;
    S.initialise();
    cout<<"enter an infix expression:";
    while( a[i]!= '\0')
    {
        cin>>a[i];
    }
  /*  int len = strlen(a);
    for( i=0; i<len; i++)
    {
       S.push(a[i]);

*/    //parmatch(p,q,a);
    infixtopostfix(a,b);
}

/*void parmatch(stack r,stack s,char a[])
{

    for(int i=0;a[i]!='\0';i++)
    {
        if(a[i]=='(')
           {
               int x = a[i];
               r.push(x);
            }
        if(a[i]== ')')
        {
            int val;
            val= r.pop();
        }
    int y=r.empty();
    if(y==1)
    {

        cout<<"ëxpression valid";
    }
    else
    {
        cout<<"expression invalid";

    }
    }
}*/

int precedence(char x)
{
    if(x =='(') return(0);
    if(x=='+' || x=='-') return(1);
    if(x=='*' || x=='/') return(2);
}

void infixtopostfix( char in[], char post[])
{
 stack t;
 char x,y;
 int i,j;
 for (i=0; in[i]!='\0';i++)
 {
  y=in[i];
  if(isalnum(y))
   {
       post[i++]=y;
   }
       else if(y=='(')
            {
               t.push(y);
           }
           else if(y==')')
           {
               while(x=t.pop()!='(')
                        post[j++]=x;

           }
        else
        {
            while(precedence(y)<= precedence(t.eletop()) && ! t.empty())
                  {

                    x=t.pop();

                    post[j++]=x;
                    }
        }
 }

while(!t.empty())
{
    x=t.pop();
    post[j++]=x;
}
}




