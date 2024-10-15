#include<bits/stdc++.h>
using namespace std;

struct node
{
    int item;
    node *next;
};

class Queue
{
    private:
    node* front,*rear;
    
    public:
    Queue();
    void insert(int);
    bool isEmpty();
    node* getRear();
    node* getFront();
    void del();
    ~Queue();
    int count();
    
};

int Queue::count()
{
    node *t;
    int c=0;
    t=front;
    while(t)
    {
        c++;
        t=t->next;
    }
}

Queue::~Queue()
{
    while(!isEmpty())
    {
        del();
    }
}

void Queue::del()
{
    node *t;
    if(!isEmpty())
    {
        t=front;
        front=front->next;
        if(front==NULL)
        {
            rear=NULL;
        }
        delete t;
    }
}

node* Queue::getFront()
{
    return front;
}

node* Queue::getRear()
{
    return rear;
}

bool Queue::isEmpty()
{
    return rear==NULL;
}

void Queue::insert(int data)
{
    node *n=new node;
    n->item=data;
    n->next=NULL;
    if(isEmpty())
    {
        front=rear=n;
    }
    else
    {
    rear->next=n;
    rear=n;
    }
}

Queue::Queue()
{
    front=rear=NULL;
}

