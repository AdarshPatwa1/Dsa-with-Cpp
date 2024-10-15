#include<bits/stdc++.h>
using namespace std;

struct node{
    node *prev;
    int item;
    node *next;
};

class Deque{
    private:
    node *front,*rear;

    public:
    Deque();
    Deque(Deque& other); // Copy constructor
    Deque& operator=(Deque& other);
    void insertFront(int);
    void insertRear(int);
    void deleteFront();
    void deleteRear();
    node* getFront();
    node* getRear();
    ~Deque();
    bool isEmpty();
};

Deque::Deque()
{
    front=rear=NULL;
}

Deque::~Deque()
{
    while (front)
    {
        deleteFront();
    }
}

bool Deque::isEmpty()
{
    return front==rear;
}

void Deque::insertFront(int data)
{
    node *n= new node;
    n->item=data;
    n->prev=NULL;
    n->next=front;
    if(front){
    front->prev=n;
    }
    else{
        rear=n;
    }
    front=n;
}

void Deque::insertRear(int data)
{
    node *n=new node;
    n->item=data;
    n->prev=rear;
    n->next=NULL;
    if(rear){
        rear->next=n;
    }
    else{
        front=n;
    }
    rear=n;
}

void Deque::deleteFront()
{
    node *t;
    if(front)
    {
        t=front;
        if(front==rear)
        {
            front=rear=NULL;
        }
        else
        {
            front=front->next;
            front->prev=NULL;
        }
        delete t;
    }
}

void Deque::deleteRear()
{
    node *t;
    if(rear)
    {
        t=rear;
        if(front==rear)
        {
            front=rear=NULL;
        }
        else{
            rear=rear->prev;
            rear->next=NULL;
        }
        delete t;
    }
}

node* Deque::getFront()
{
    return front;
}
node* Deque::getRear()
{
    return rear;
}

Deque::Deque(Deque& other) {
    front = rear = NULL; 
    if (other.front == NULL) {
        return;
    }
    
    // Deep copy the other deque's nodes
    node* temp = other.front;
    while (temp) {
        insertRear(temp->item); // Copy each node's data by inserting at the rear
        temp = temp->next;
    }
}

// Assignment operator overloading (no const)
Deque& Deque::operator=(Deque& other) {
    if (this != &other) { 
        // Clean up the current deque
        while (front) {
            deleteFront();
        }
        
        // Deep copy from the other deque
        node* temp = other.front;
        while (temp) {
            insertRear(temp->item); // Copy each node's data
            temp = temp->next;
        }
    }
    return *this;
}