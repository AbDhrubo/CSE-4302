#include<iostream>
#include<algorithm>
using namespace std;

template <class atype>
atype find(atype* array, int size, int n){
    sort(array, array+n);
    return array[size-n];
}

int main(){
    int arr[] = {1,2,3,4, 5};
    cout << find(arr,5,2) << endl;
    float arr2[] = {11.1, 12.2, 13.3, 14.4, 15.5};
    cout << find(arr2, 5, 2) << endl;
    return 0;
}