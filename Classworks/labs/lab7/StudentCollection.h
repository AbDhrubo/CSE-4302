#define MAX 10
#include<bits/stdc++.h>
using namespace std;

class StudentCollection{
    private:
        string names[MAX];
        double grades[MAX];
        int total;
    public:
        StudentCollection(){
            total = 0;
        }
        int getIndex(string s){
            for(int i = 0; i<total; i++){
                if(s == names[i]) return i;
            }
            return -1;
        }
        double operator[] ( string& name) {
            if (grades[getIndex(name)] != -1)return grades[getIndex(name)];
            return -1;
        }

        double& operator[](const string& name) {
            if (grades[getIndex(name)] != -1) return grades[getIndex(name)];
        }

        void addStudent (string name, double grade){
            if(total == MAX) {
                cout << "Max limit reached" << endl;
                return ;
            }
            names[total] = name;
            grades[total] = grade;
            total ++;
        }
};