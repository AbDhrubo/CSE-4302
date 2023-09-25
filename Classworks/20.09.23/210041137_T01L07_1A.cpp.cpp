#include<bits/stdc++.h>
#include "StudentCollection.h"
using namespace std;

int main(){
    StudentCollection s1;
    s1.addStudent("dhrubo", 3.5);
    s1.addStudent("akib", 3.8);
    s1.addStudent("sahil", 3.9);
    cout << s1["sahil"] << endl;
    s1["akib"] = 4;
    cout << s1["akib"];

}