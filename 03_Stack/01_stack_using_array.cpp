#include<bits/stdc++.h>
#include "01_array.cpp"
// drag & drop the 01_array.cpp file into 01_stack folder

using namespace std;

class Stack:private Array // private inheritance because we dont want to access its methods 
{
    public:
    Stack(int);
    Stack(Stack &); // copy constructor
    void push(int);
    int peek();
    void pop();
    ~Stack();
    bool isFull(); // virtual bool full(); if stack & array's full method of same name overriding concept so we use virtual 
    virtual bool isempty();
    int getstacksize();
    void operator=(Stack &);
};

void Stack::operator=(Stack &s){
    Array::operator=(s);
}

int Stack::getstacksize(){
    return getcap();
}

Stack::Stack(int cap):Array(cap) // child class calling parent class constructor for parameter
{

}

Stack::Stack(Stack &S):Array(S)
{

}

void Stack::push(int data){
    if(full())
    {
        cout<<"Stack Overflow";
    }
    else
    {
        append(data);
    }
}

int Stack::peek(){
    if(!isempty()){
        return get(count()-1);
    }
    else{
        cout<<"Stack is empty";
    }
    return 0;
}

void Stack::pop(){
    if(isempty())
    {
        cout<<"Stack Underflow";
    }
    else
    {
        isdelete(count()-1);
    }
}

Stack::~Stack()
{
    // we don't need to do anything when ~stack destructor is defined it calls Array class destructor
}

bool Stack::isFull()
{
    return full();
    // return Array::full(); //if stack & array's full method of same name overriding concept
}

bool Stack::isempty()
{
    return Array::isempty();
}

void reverseStack(Stack &s1){
    Stack s2(s1.getstacksize());

    while(!s1.isempty())
    {
        s2.push(s1.peek()); 
        s1.pop();
    }
    s1=s2;
}

void pushInStack(Stack &s, Stack &minStack,int data)
{
    s.push(data);
    if(minStack.isEmpty())
        minStack.push(data);
    else
    {
        if(data> minStack.peek())
            minStack.push(minStack.peek());
        else
            minStack.push(data);
    }
}
void popFromStack(Stack &s, Stack &minStack)
{
    s.pop();
    minStack.pop();
}

int main(){
    // Stack s(5);
    // s.push(10);
    // s.push(20);
    // s.push(30);
    // s.push(40);
    // s.push(50);
    // cout<<s.peek();
    // cout<<endl;
    // reverseStack(s);
    // cout<<s.peek();
    Stack s(5);
    Stack minStack(5);
    pushInStack(s,minStack,50);
    cout<<endl<<"Current minimum Value is "<<minStack.peek();
    pushInStack(s,minStack,40);
    cout<<endl<<"Current minimum Value is "<<minStack.peek();
    pushInStack(s,minStack,60);
    cout<<endl<<"Current minimum Value is "<<minStack.peek();
    pushInStack(s,minStack,70);
    cout<<endl<<"Current minimum Value is "<<minStack.peek();
    pushInStack(s,minStack,30);
    cout<<endl<<"Current minimum Value is "<<minStack.peek();
    cout<<endl<<"Poping Start";
    popFromStack(s,minStack);
    cout<<endl<<"Current minimum Value is "<<minStack.peek();
    popFromStack(s,minStack);
    cout<<endl<<"Current minimum Value is "<<minStack.peek();
    popFromStack(s,minStack);
    cout<<endl<<"Current minimum Value is "<<minStack.peek();
    popFromStack(s,minStack);
    cout<<endl<<"Current minimum Value is "<<minStack.peek();
    popFromStack(s,minStack);
    cout<<endl<<"Current minimum Value is "<<minStack.peek();
    return 0;
}