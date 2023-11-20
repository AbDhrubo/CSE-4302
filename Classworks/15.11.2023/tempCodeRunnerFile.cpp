#include<iostream>
#include<algorithm>
using namespace std;

template <class atype>
int find(atype* array, int size, int n){
    sort(array, array+n);
    return array[size-n];
}

int main(){
    int arr[] = {1,2,3,4, 5};
    cout << find(arr,5,2) << endl;
    float arr2[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    cout << find(arr2, 5, 2) << endl;
    return 0;
}