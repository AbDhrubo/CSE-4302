#include<iostream>
using namespace std;

void f(int &a){
    a = 5;
}

int main(){
    int a,b;
    a = 10;
    f(a);
    cout << a << endl;
    return 0;
}