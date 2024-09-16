#include<bits/stdc++.h>
#include<iostream>
#include<stdio.h>
using namespace std;

struct node{
    int item;
    node* next;
};
class CLL{
    private:
    node *last;

    public:
    CLL();
    void insertatstart(int);
    void insertatlast(int);
    node* search(int);
    void insertafter(node *,int);
    void deletefirst();
    void deletelast();
    void deletespecific(node *);
    ~CLL();
};
CLL::CLL()
{
    last=NULL;
}

void CLL::insertatstart(int data)
{
    node *n=new node;
    n->item=data;
    if(last)
    {
        n->next=last->next;
        last->next=n;
    }
    else
    {
        n->next=n;
        last=n;
    }
}

void CLL::insertatlast(int data)
{
    node *n=new node;
    n->item=data;
    if(last)
    {
        n->next=last->next;
        last->next=n;
        last=n;
    }
    else
    {
        n->next=n;
        last=n;
    }
}

node* CLL::search(int data)
{
    node *t;
    if(last)
    {
        t=last->next;
        if(last->item==data)
        {
            return last;
        }
        while(t!=last){
            if(t->item==data)
            {
                return t;
            }
            t=t->next;
        }
    }
    return NULL;

    // Another approach using do while
    // if(last)
    // {
    //     t=last->next;
    //     do
    //     {
    //         if(t->item==data)
    //         {
    //             return t;
    //         }
    //         t=t->next;
    //     } while (t!=last->next)
        
    // }
    // return NULL;
}

void CLL::insertafter(node *temp,int data)
{
    //if therse is a list than we will insert if it is null then no operation
    if(last)
    {
        node *n=new node;
        n->items=data;
        n->next=temp->next;
        temp->next=n;
        if(temp==last)
        {
            last=n;
        }
    }
}

void CLL::deletefirst()
{
    if(last)
    {
        node *t;
        t=last->next;
        if(last->next==last)
        {
            last=NULL;
        }
        else
        {
            last->next=t->next;
        }
        delete t;
    }
}

void CLL::deletelast()
{
    if(last)
    {
        node *t;
        t=last;
        while(t->next!=last){
            t=t->next;
        }
        if(t==last)
        {
            delete last;
            last=NULL;
        }
        else
        {
        t->next=last->next;
        delete last;
        last=t;
        }
    }
}

void CLL::deletespecific(node *temp)
{
    if(last)
    {
        node *t;
        t=last->next;
        while(t->next!=temp)
        {
            t=t->next;
        }
        t->next=temp->next;
        if(t==temp)
        {
            last=NULL;
        }
        else if(temp==last)
        {
            last=t;
        }
        delete temp;
    }
}

CLL::~CLL()
{
    if(last)
    {
        deletefirst();
    }
}