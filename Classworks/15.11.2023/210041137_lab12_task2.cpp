#include<iostream>
using namespace std;

template <class Type>
class my_stack{
    private:
        int top;
        Type first;
        Type st[1000];
    public:
        my_stack(){
            top = -1;
        }
        void push(Type var){
            st[++top] = var;
            if(!top) first = var;
        }
        Type pop(){
            return st[top--];
        }
        Type peek(){
            return first;
        }

};

int main(){
    my_stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    cout << s.peek() << endl;
    cout << s.pop();
}