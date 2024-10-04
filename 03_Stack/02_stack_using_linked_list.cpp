#include<bits/stdc++.h>
using namespace std;

struct node
{
    int item;
    node *next;
}
class Stack
{
    private:
    node *top;

    public:
    Stack();
    Stack(Stack&);
    void push(int);
    bool isEmpty();
    int peek();
    void pop();
    ~Stack();
    void reverse();
    void operator=(Stack &S);
};

void Stack::operator=(Stack &S)
{
    node *t,*n,*p=NULL;
    t=S.top;
    while(t)
    {
        n=new node;
        n->item=t->item;
        if(top==NULL)
            top=n;
        else
            p->next=n;
        t=t->next;
        p=n;
    }
    if(p!=NULL)
        p->next=NULL;
}
Stack::Stack(Stack &S)
{
    node *t,*n,*p=NULL;
    t=S.top;
    while(t)
    {
        n=new node;
        n->item=t->item;
        if(top==NULL)
            top=n;
        else
            p->next=n;
        t=t->next;
        p=n;
    }
    if(p!=NULL)
        p->next=NULL;
}

void reverse(Stack &s1)
{
    Stack s2;
    while(!s1.isEmpty())
    {
        s2.push(s1.peek());
        s1.pop();
    }
    s1=s2;
}

Stack::Stack()
{
    top=NULL;
}

Stack::~Stack()
{
    while(top)
    {
        pop();
    }
} 

bool Stack::isEmpty()
{
    return top==NULL;
}

void Stack::push(int data)
{
    node *n=new node;
    n->item=data;
    n->next=top;
    top=n;
    // if(is_empty())
    // {
    //     n->next=NULL
    //     top=n;
    // }
    // else
    // {
    //     n->next=top;
    //     top=n;
    // }
    // if(top){
    //     n->next=top;
    //     top=n;
    // }
    // else
    // {
    //     n->next=NULL
    //     top=n;
    // }
}

int Stack::peek()
{
    if(top==NULL)
    {
        cout<<"Stack Underflow";
        return -1;
    }
    return top->item;
}

void Stack::pop()
{
    node *r;
    if(isEmpty())
    {
        cout<<"Stack Underflow";
    }
    else
    {
        r=top;
        top=top->next;
        delete r;
    }
}

void Stack::reverse()
{
    node *t1,*t2;
    if(top && top->next) // checking if top && top->next not equal to null than if statement works otherwise no changes
    {
        t2=NULL;
        do{
            t1=top;
            top=top->next;
            t1->next=t2;
            t2=t1;
        }while(top->next);
        top->next=t1;
    }
}

int len(int x)
{
    int count=0;
    while(x)
    {
        x=x/10;
        count++;
    }
    return count;
}
bool isPalindrome(int x)
{
    Stack s;
    int l=len(x);
    int i=l/2;
    while(i)
    {
        s.push(x%10);
        x/=10;
        i--;
    }
    if(l%2)
    {
        x/=10;
    }
    while(x)
    {
        if(x10==s.peek())
        {
            s.pop();
            x/=10;
        }
        else{
            return false;
        }
    }
    return true;
}

int infixtopostfix()