#include<iostream>
using namespace std;

typedef struct {
    string courseName;
    float marks;
    float cgpa;
} course;

class Student{
    private:
        string fname;
        string lname;
        int id;
        int byear;
        course c[20];
        int noc;
        static int no_of_students;
    public:
        Student(string f, string l, int i){
            fname = f;
            lname = l;
            id = i;
            noc = 0;
        }   
};

int main(){

}