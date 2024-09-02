#include<bits/stdc++.h>
#include <iostream>
using namespace std;

class DynArray
{
    private:
    int capacity;
    int lastindex;
    int *ptr;

    public:
    DynArray(int);
    void doublearray();
    void halfarray();
    int size();
    bool isempty();
    void append(int);
    void insert(int,int);
    void edit(int,int);
    void del(int);
    bool isfull();
    int get(int);
    int count();
    int find(int);
    ~DynArray();
};

DynArray::DynArray(int size){
    capacity=size;
    lastindex=-1;
    ptr=new int[capacity];
}

void DynArray::doublearray(){
    int *temp = new int[capacity*2]; // create new array of double size & assign it to tempoarary pointer
    for(int i=0;i<=lastindex;i++){
        temp[i]=ptr[i];  // copy the old array into new array
    }
    delete []ptr; // delete older array
    ptr=temp; // copy new array into instance
    capacity*=2; // double the instance capacity
}

void DynArray::halfarray(){
    int *temp = new int[capacity/2];
    for(int i=0;i<=lastindex;i++){
        temp[i]=ptr[i];  // copy the old array into new array
    }
    delete []ptr;
    ptr=temp;
    capacity/=2;
}

int DynArray::size(){ return capacity; }

bool DynArray::isempty(){ return lastindex==-1; }

void DynArray::append(int data){
    if(isfull()){
        doublearray();
    }
    lastindex++;
        ptr[lastindex]=data;
}

void DynArray::insert(int index, int value){
    if(index<0 || index>lastindex+1){
        cout<<"Invalid index";
    }
    else {
    if(isfull()){
        doublearray();
    }
    for(int i=lastindex;i>=index;i--){
            ptr[i+1]=ptr[i];
            
        }
        ptr[index]=value;
        lastindex++;
    }
}

void DynArray::edit(int index,int data){
    if(index>=0 && index<=lastindex){
        ptr[index]=data;
        }
}

void DynArray::del(int index){
        if(isempty()){
            cout<<"array is empty";
        }else if(index<0 || index>lastindex+1){
            cout<<"invalid index";
        }else{
            
        for(int i=index;i<lastindex;i++){
        ptr[i]=ptr[i+1];
        }
        lastindex--;
        if(capacity/2==lastindex+1){
            halfarray();
            }
        }
}

bool DynArray::isfull()
{
    return lastindex==capacity-1;
}

int DynArray::get(int index){
        if(index>=0 && index<=lastindex){
            return ptr[index];
        }
        cout<<"invalid index or empty";
        return -1;
    }

int DynArray::count(){
        return lastindex+1;
    }

int DynArray::find(int value){
        for(int i=0;i<=lastindex;i++){
            if(ptr[i]==value);{
                return i;
            }
        }
        return -1;
    }

DynArray::~DynArray(){
    delete []ptr;
}
int main(){
    DynArray arr(10);
    arr.append(10);
    arr.append(30);
    arr.append(50);
    arr.append(40);
    cout<<arr.size();
    arr.insert(2,30);
    arr.insert(1,20);

}