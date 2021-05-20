# Dynamic binding v.s Static binding
## run     
https://coliru.stacked-crooked.com/a/4aca1d23c5e2f8a6    
## code   
```cpp
#include <iostream>
using namespace std;
class A{
public:
    virtual void print_type(){
        cout<< "A"<< endl;
    }
};
class B:public A{
public:
    void print_type(){
        cout<<"B"<<endl;
    }
};
class C:public A{
public:
    void print_type(){
        cout<<"C"<<endl;
    }
};
int main(){
    //dynamic type v.s static type
    C* c_ptr = new C(); //static type -> A dynamic type -> A 
    B* null_ptr = NULL; //static type->B no dynamic type(NULL)
    A* a_ptr = new C(); //static type -> C dynamic type -> B
    
    a_ptr->print_type();
    null_ptr->print_type(); //null_ptr can call method "print_type" though the ptr is NULL(The type has been decided before compilation)
    c_ptr->print_type(); 
    
    a_ptr = new C();
    a_ptr->print_type();
}
    //sum up
    //1. Static binding occurs at compile time,dynamic binding occurs at runtime.
    //2. Static type couldn't be changed, dynamic type counld be changed.  
    //3. Dont redefine non-virtual function when inheriting.
```
