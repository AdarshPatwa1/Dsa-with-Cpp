#include<bits/stdc++.h>
#include <iostream>
#include<stdio.h>
using namespace std;

class node{
    int item;
    node *next;
};

class SLL{
    private:
    node *start;

    public:
    SLL();
    void insertatstart(int);
    void insertatlast(int);
    node* search(int);
    void insertafter(node *,int);
    void deletefirst();
    void deletelast();
    void deletespecific(node *);
    ~SLL();
};
SLL::~SLL(){
    while(start)
    {
        deletefirst();
    }
}

void SLL::deletespecific(node *temp){
    node *t;
    if(start==NULL)
    {
        cout<<"\nunderflow";
    }
    else
    if(temp)
    {
        if(start==temp)
        {
            start=temp->next;
            delete temp;
        }
        else
        {
            t=start;
            while(t->next!=temp)
            {
                t->next;
            }
            t->next=temp->next;
            delete temp;
        }
    }
}

void SLL::deletelast(){
    node *t;
    if(start==NULL){
        cout<<"list is empty";
    }
    else if(start->next==NULL){
        delete start;
        start=NULL;
    }
    else{
        t=start;
        while(t->next->next!=NULL){
            t=t->next;
        }
        delete t->next;
        t->next=NULL;
    }
}
void SLL::deletefirst(){
    node *t;
    if(start){
        t=start;
        start=start->next;
        delete t;
    }
}

void SLL::insertafter(node *ptr,int data){
    node *n=new node;
    n->item=data;
    n->next=ptr->next;
    ptr->next=n;
}

node* SLL::search(int data){
    node *t;
    t=start;
    while(t!=NULL){
        if(t->item==data){
            return t;
        }
        t=t->next;
    }
    return NULL;
}

SLL::SLL(){
    start = NULL; // to use NULL we have to include stdio.h
}

void SLL::insertatstart(int data){
    node *n=new node;
    n->item=data;
    n->next=start;
    start=n;
}

void SLL::insertatlast(int data){
    node *t;
    node *n=new node;
    n->item=data;
    n->next=NULL;
    if(start==NULL){
        start=n;
    }
    else{
        t=start;
        while(t->next!=NULL){ //to check if t->next=null or not if null then we assisn n if not then
            t=t->next         // will move ahead
        }
        t->next=n;
    }

}