#include<iostream>
using namespace std;

int main (){
    enum days_of_the_week {sun, mon, tues, wed, thurs, fri, sat};
    days_of_the_week today = wed;
    cout << today << endl;
    enum gender {male, female};
    gender pl_gender = female;
    cout << pl_gender << endl;
    return 0;
}