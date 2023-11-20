#include<iostream>
using namespace std;

class Exception{
    public:
        string what(){
            return "Cannot pop from empty stack";
        }
};

class Exception2{
    public:
        string what(){
            return "Overflow";
        }
};

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
            try{
                if(top == 999) throw Exception2();
                st[++top] = var;
                if(!top) first = var; 
            }
            catch(Exception2 e2){
                cout << e2.what() << endl;
            }
        }

        Type pop(){
            try{
                if(top == -1){
                    throw Exception();
                }
                return st[top--];
            }
            catch(Exception e){
                cout << e.what() << endl;
            }
        }
        
        Type peek(){
            return first;
        }

};

int main(){
    my_stack<int> s;
    my_stack<float> s2;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    cout << s.peek() << endl;
    cout << s.pop() << endl;
    for(int i = 0; i<5 ; i++) s.pop();
    for(int i = 0; i<5; i++) {
        s2.push(1.1*(i+5));
        cout << s2.peek() << endl;
    }
    for(int i = 0; i<5; i++){
        cout << s2.pop() << endl;
    }
    s2.pop();
}