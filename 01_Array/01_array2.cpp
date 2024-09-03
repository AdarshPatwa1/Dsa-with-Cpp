#include "01_array.cpp"
class ExtendedArray:public Array // inheritance
{
    public:
    ExtendedArray(int);
    int greatest();
};
ExtendedArray::ExtendedArray(int cap):Array(cap){}
int ExtendedArray::greatest(){
    int max;
    if(isempty()){
        cout<<"\narray is empty";
        return -1;
    }
    max=get(0);
    for(int i=1;i<count();i++){
        if(max<get(i)){
            max=get(i);
        }
    }
    return max;
}
int main(){
    ExtendedArray obj(5);
    obj.append(20);
    obj.append(70);
    obj.append(30);
    obj.append(10);
    cout<<obj.greatest()<<endl;
}