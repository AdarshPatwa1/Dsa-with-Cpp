#include<bits/stdc++.h>
#include <iostream>
using namespace std;
class Array{
    private:
    int capacity;
    int lastindex;
    int *ptr;
    public:
    Array(int);
    bool isempty();
    void append(int);
    void printarray();
    void insert(int,int);
    void edit(int,int);
    void isdelete(int);
    bool full();
    int get(int);
    int count();
    ~Array();
    int find(int);
};  

Array::Array(int size){
        lastindex=-1;
        capacity=size;
        ptr=new int[capacity];
}
    
bool Array::isempty(){
        return lastindex==-1;
}
    
void Array::append(int x){
    if(lastindex==capacity-1){
        cout<<"array is full";
        }
    else{
        lastindex++;
        ptr[lastindex]=x;
        }
}
    
void Array::printarray(){
    for(int i=0;i<=lastindex;i++){
        cout<<ptr[i];
            
        }    
}
    
void Array::insert(int index,int value){
    int i;
    if(index<0 || lastindex==capacity-1){
            cout<<"array is full";
        }
    else if(index>lastindex+1){
            cout<<"invalid index";
        }
    else{
        for(int i=lastindex;i>=index;i--){
            ptr[i+1]=ptr[i];
            
        }
    ptr[index]=value;
    lastindex++;
        }
}
    
void Array::edit(int index,int value){
    if(index>=0 && index<=lastindex){
        ptr[index]=value;
        }
}
    
void Array::isdelete(int index){
    if(isempty()){
            cout<<"array is empty";
        }
    else if(index<0 || index>lastindex+1){
            cout<<"invalid index";
        }
    for(int i=index;i<lastindex;i++){
        ptr[i]=ptr[i+1];
        }
    lastindex--;
}
    
bool Array::full(){
    return lastindex==capacity-1;
}
    
int Array::get(int index){
    if(index>=0 && index<=lastindex){
            return ptr[index];
        }
    cout<<"invalid index or empty";
    return -1;
}

int Array::count(){
    return lastindex+1;
}

Array::~Array(){
    delete[]ptr;
}

int Array::find(int value){
    for(int i=0;i<=lastindex;i++){
        if(ptr[i]==value);{
            return i;
        }
    }
    return -1;
}

// int main() {
//     Array a(5);
//     a.append(3);
//     a.append(5);
//     a.insert(0,4);
//     a.edit(1,2);
//     a.isdelete(2);
//     a.printarray();
//     return 0;
// }