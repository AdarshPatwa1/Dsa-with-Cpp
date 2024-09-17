#include<bits/stdc++.h>
using namespace std;

struct node{
    node* prev;
    int item;
    node* next;
};
class CDLL{
    private:
    node *start;

    public:
    CDLL();
    void insertatstart(int);
    void insertatlast(int);
    node* search(int);
    void insertafter(node *,int);
    void deletefirst();
    void deletelast();
    void deletespecific(node *);
    ~CDLL();
};

CDLL::CDLL(){
    start=NULL;
};
void CDLL::insertatstart(int data){
    node *n=new node;
    n->item=data;
    if(start==NULL)
    {
        n->prev=n;
        n->next=n;
        start=n;
    }
    else
    {
        n->prev=start->prev;
        n->next=start;
        n->prev->next=n;
        n->next->prev=n;
        start=n;
    }
}

void CDLL::insertatlast(int data){
    node *n=new node;
    n->item=data;
    if(start==NULL)
    {
        n->prev=n;
        n->next=n;
        start=n;
    }
    else
    {
        n->prev=start->prev;
        n->next=start;
        n->prev->next=n;
        n->next->prev=n;
    }
}

node* CDLL::search(int data){
    node *t;
    t=start;
    if(t)
    {
        do{
            if(t->item==data)
            {
                return t;
            }
            t=t->next;
        }while(t!=start)
    }
    return NULL;
}

void CDLL::insertafter(node *temp,int data){
    if(temp)
    {
        node *n=new node;
        n->item=data;
        n->prev=temp;
        n->next=temp->next;
        temp->next->prev=n;
        temp->next=n;
    }
}

void CDLL::deletefirst(){
    node *r;
    if(start)
    {
        r=start;
        if(r->next==r)
        {
            delete r; 
            start=NULL;
        }
        else
        r->next->prev=r->prev;
        r->prev->next=r->next;
        start=r->next;
        delete r;

    }
}

void CDLL::deletelast(){
    node *r;
    if(start)
    {
        if(start->next==start)
        {
            delete start;
            start=NULL;
        }
        else
        {
        r=start->prev;
        r->prev->next=start;
        start->prev=r->prev;
        delete r;
        }
    }
}

void CDLL::deletespecific(node *temp){
    if(temp)
    {
        if(start==start->next)
        {
            delete start;
            start=NULL;
        }
        else
        {
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
            if(start==temp)
            {
                start=temp->next;
            }
        delete temp;
        }
    }
}

CDLL::~CDLL(){
    while(start)
    {
        deletefirst();
    }
}