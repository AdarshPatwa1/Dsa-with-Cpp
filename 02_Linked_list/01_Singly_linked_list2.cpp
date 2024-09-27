#include <iostream>
#include "01_Singly_linked_list.cpp"
using namespace std;

int count(SLL &obj)
{
    if(obj.start)
    {
    node *t=obj.start;
    int count=0;
        while(t!=NULL)
        {
            count++;
            t=t->next;
        }
        return count;
    }
    return 0;
}

void reverse(SLL &obj)
{
    if(obj.start)
    {
        node *prev = NULL;
        node *current = obj.start;
        node *next = NULL;
        
        while(current != NULL)
        {
            next = current->next;  // Store the next node
            current->next = prev;  // Reverse the link now pointing from-> to <-
            prev = current;        // Move prev and current one step forward
            current = next;
        }
        
        obj.start = prev;  // Update the head to the new first node
    }
}

node* middlenode(SLL &obj)
{
    if(obj.start)
    {
        int t=count(obj)/2;
        node *n=obj.start;
        for(int i=0;i<t;i++)
        {
            n=n->next;
        }
        return n;

    // another approach using two pointer->

    //     node *slow = obj.start;
    // node *fast = obj.start;

    // Move `fast` two steps and `slow` one step until `fast` reaches the end
    // while(fast != nullptr && fast->next != nullptr)
    // {
    //     slow = slow->next;
    //     fast = fast->next->next;
    // }

    // return slow;
    }
    return NULL;
}

int cycle(SLL &obj)
{
    node *t1=obj.firstnode();
    node *t2=t1;
    do{
        if(t1==NULL)
        {
            return 0;
        }
        if(t1->next!=NULL)
        {
            t1=t1->next->next;
        }
        else
        {
            retuen 0;
        }
        t2=t2->next;
    }while(t1!=t2)
    return 1;
}
int lengthofcycle(SLL &obj)
{
    int count=1;
    node *t1,*t2;
    if(cycle(obj))
    {
        t1=t2=obj.firstnode();
        do{
            t1=t1->next->next;
            t2=t2->next;
        }while(t1!=t2)
        while(t1->next!=t2)
        {
            count++;
            t1=t1->next;
        }
        return count;
    }
    return 0;
}

void sort(SLL &obj)
{
    if(obj.start && obj.start->next){
        int c=count(obj);
        while(c>0){
            node* t1=obj.start;
            node* t2=obj.start->next;
            while(t2!=NULL){
                if(t1->item>t2->item){
                    swap(t1,t2);
                }
                t1=t1->next;
                t2=t2->next;
            }
            c--;
        }
    }
}

void swap(node *t1,node *t2){
    int temp=t1->item;
    t1->item=t2->item;
    t2->item=temp;
}

node * merge(SLL &obj1,SLL &obj2){
    if(!obj1.start)return obj2;
    if(!obj2.start)return obj1;
    node *temp=obj1.start;
    while(temp->next){
        temp=temp->next;
    }
    temp->next=obj2.start;
    return obj1.start;
}

node* mergetwosortedlist(SLL &obj1,SLL &obj2){
    node *newnode=merge(obj1,obj2);
    SLL mergelist;
    mergelist.start=newnode;
    sort(mergelist);
    return mergelist;
}

node* addtwonum(node *l1,node *l2){
    node *n=new node;
    node *temp=n;
    int carry=0;
    while(l1 || l2 || carry){
        int sum=carry;

        if(l1){
            sum+=l1->item;
            l1=l1->next;
        }
        if(l2){
            sum+=l2->item;
            l2=l2->next;
        }
        carry=sum/10;
        sum=sum%10;
        node *t=new node;
        t->item=sum;
        temp->next=t;
        temp=temp->next;
    }
    return n;
}

class Polynomial{
    struct node{
        int coeff;
        int deg;
        node* next;
    };
    node *start;
    public:
    Polynomial();
    void insert(int,int);
    Polynomial addtwopolynomial(Polynomial &);
};
Polynomial::Polynomial(){
    start=NULL;
}

void Polynomial::insert(int c, int d){
    node *n=new node;
    node *t,*p;
    n->coeff=c;
    n->deg=d;
    if(start==NULL){
        n->next=NULL;
        start->next=n;
    }
    else{
        t=start;
        p=NULL;
        if(t->deg<d){
            n->next=t;
            start=n;
        }
        else{
            p=t;
            t=t->next;
            while(t){
                if(t->deg<d){
                    n->next=t;
                    p->next=n;
                    break;
                }
                p=t;
                t=t->next;
            }
            if(t==NULL){
                n->next=NULL;
                t->next=n;
            }
        }
    }
}

Polynomial Polynomial::addtwopolynomial(Polynomial &p1){
    Polynomial result;
    node* t1 = start;
    node* t2 = p.start;
    
    while (t1 != NULL && t2 != NULL) {
        if (t1->deg == t2->deg) {
            result.insert(t1->coeff + t2->coeff, t1->deg);
            t1 = t1->next;
            t2 = t2->next;
        }
        else if (t1->deg > t2->deg) {
            result.insert(t1->coeff, t1->deg);
            t1 = t1->next;
        }
        else {
            result.insert(t2->coeff, t2->deg);
            t2 = t2->next;
        }
    }
    
    while (t1 != NULL) {
        result.insert(t1->coeff, t1->deg);
        t1 = t1->next;
    }
    
    while (t2 != NULL) {
        result.insert(t2->coeff, t2->deg);
        t2 = t2->next;
    }
    
    return result;
}

