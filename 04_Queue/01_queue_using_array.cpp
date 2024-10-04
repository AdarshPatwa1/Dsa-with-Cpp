#include<bits/stdc++.h>
using namespace std;

class Queue
{
    private:
    int capacity
    int front,rear;
    int *ptr;

    public:
    Queue(int);
    Queue(Queue &); // copy constructor
    void insert(int);
    bool isFull();
    bool isEmpty();
    int getRear(); //to get the rear's element
    int getFront();
    void deletefront();
    ~Queue();
    int count();
    Queue& opeartor=(Queue &);
};

Queue::Queue(int cap)
{
    capacity=cap;
    front=-1;
    rear=-1;
    ptr=new int[cap];
}

Queue::Queue(Queue &q)
{
    capacity=q.capacity;
    front=q.front;
    rear=q.rear;
    ptr=new int[capacity];
    int n=q.count();
    int i=q.front;
    while(n)
    {
        ptr[i]=q.ptr[i];
        if(i==capacity-1)
        {
            i=0;
        }
        else
        {
            i++;
        }
        n--;
    }
}

Queue& Queue::opeartor=(Queue&q)
{
    capacity=q.capacity;
    front=q.front;
    rear=q.rear;
    if(ptr!=NULL)
    {
        delete[]ptr;
    }
    ptr=new int[capacity];
    int n=q.count();
    int i=q.front;
    while(n)
    {
        ptr[i]=q.ptr[i];
        if(i==capacity-1)
        {
            i=0;
        }
        else
        {
            i++;
        }
        n--;
    }
}

Queue::~Queue()
{
    delete []ptr;
}

void Queue::insert(int data)
{
    if(isFull()) // 1st case is if stack is full when insertion not possible
    {
        cout<<"Stack Overflow";
    }
    else if(isEmpty()) // if front and rear at -1 that means empty
    {
        front=0;
        rear=0;
        ptr[rear]=data;
    }
    else if(rear==capacity-1) //when rear at capacity-1 and front !=0
    { // front is not checked because if front at 0 and rear at capacity -1 then queue is full and it never comes to this case it gets true in first case
        rear=0;
        ptr[rear]=data;
    }
    else // when all cases ok that means queue is not empty so the data is inserted
    {
        rear++;
        ptr[rear]=data;
    }
}

bool Queue::isFull()
{
    return front==0 && rear==capacity-1 ||rear+1==front;
}

bool Queue::isEmpty()
{
    return rear==-1;
}

int Queue::getRear()
{
    if(!isEmpty())
    {
        return ptr[rear];
    }
    cout<<"Queue is Empty";
    return -1;
}

int Queue::getFront()
{
    if(!isEmpty())
    {
        return ptr[front];
    }
    cout<<"Queue is Empty";
    return -1;
}

void Queue::deletefront()
{
    if(isEmpty())
    {
        cout<<"Stack Underflow";
    }
    else if(front==rear)  // no need to check if front or rear at -1 or not because if they are at -1 it's already checked inisFull()
    {
        front=-1;
        rear=-1;
    }
    else if(front==capacity-1)
    {
        front=0; 
    }
    else
    {
        front++;
    }
}

int Queue::count()
{
    if(isEmpty())
    {
        return 0;
    }
    if(front<=rear)
    {
        return rear-front+1;
    }
    return capacity-front+rear+1;
}