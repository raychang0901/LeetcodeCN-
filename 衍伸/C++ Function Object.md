# Function Object  
## run     
https://coliru.stacked-crooked.com/a/5a4d86eb0c7b2a36
## Sum up
1. Function Object(Functor) is a class, not a function.
2. Functor can be used like function through overload the operator"()"
3. if the functor needs 1 parameter then we call that"unary functor", needs 2 then call "binary functor".
4. We don't define the constructor and  destructor.
5. Functor can save its data.
## code   
```cpp
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec)
{
    for (auto& el : vec)
    {
        os << el << ' ';
    }
    cout<< endl;
    return os;
}
template<typename T>
ostream& operator<<(ostream& os, const priority_queue<T> p_q){
    priority_queue<T> tmp = p_q;
    while(!tmp.empty()){
        cout<< tmp.top()<<" ";
        tmp.pop();
    }
    cout<< endl;
    return os;
}
class cmp{
public:
    bool operator() (int a, int b)
    {
        return a>b;
    }
};
bool cmp_func(int a, int b){
    return a>b;
}
int main()
{
    cmp ccmp;
    vector<int> arr_1{1,2,3,4,5,6,0,7};
    sort(arr_1.begin(), arr_1.end(), ccmp);
    cout<< arr_1;
    vector<int> arr_2{5,4,6,0,2,3,1,7};
    sort(arr_2.begin(), arr_2.end(), cmp_func);
    cout<< arr_2;
}
```
