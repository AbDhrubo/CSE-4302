#include<iostream>
using namespace std;

typedef struct {
    string name;
    float marks;
    float grade;
}course_struct;
class Student{
    private:
        string fname;
        string lname;
        int id;
        int bYear;
        course_struct course[100];
        static int no_of_students;
        int noc = 0;
        int getidx(string s){
            for(int i = 0; i<noc; i++){
                if ( s == course[i].name) return i;
            }
            cout << "Course not found" << endl;
            return -1;
        }
        string companyy[100];
        int noi = 0;
    public:
        Student(string f, string l, int i){
            fname = f;
            lname = l;
            id = i;
        }
        void enrollingCourses(string courseName){
            course[noc].name = courseName;
            course[noc].marks = 0;
            noc++;
        }
        void obtainedMarks(string courseName, float mark){
            int idx = getidx(courseName);
            if(idx != -1) course[idx].marks = mark;
        }
        float setGPAForEachCourse(string courseName){
            int idx = getidx(courseName);
            float grad = -1;
            if(idx != -1){
                if (course[idx].marks <33) grad = 0;
                else if(course[idx].marks <40) grad = 2.75;
                else if(course[idx].marks < 50) grad = 3;
                else if(course[idx].marks < 60) grad = 3.25;
                else if(course[idx].marks < 70) grad = 3.5;
                else if(course[idx].marks < 60) grad = 3;
                else grad = 4;
                course[idx].grade = grad;
                return grad;
            }
            return grad;
        }
        float displayAverageGradePoint(){
            float gpa = 0;
            for(int i = 0; i< noc; i++){
                //if(course[i].grade) 
                gpa += course[i].grade;
                //else return 0;
            }
            return gpa/noc;
        }
        void willGraduate(){
            if(displayAverageGradePoint()) cout << "will graduate" << endl;
            else cout << "won't graduate" << endl;
        }
        void applyForScholarship(){
            if(displayAverageGradePoint()>3.8) cout << "can apply" << endl;
            else cout << "cannot apply" << endl;
        }
        void participateInInternship(string courseName, string company){
            if(getidx(courseName) != -1 && displayAverageGradePoint()>3){
                cout << "Can do internship at " << company <<" company"<< endl;
                companyy[noi] = company;
                noi++;
            } 
            else cout << "cannot do internship at " << company <<" company" << endl;
        }
        const float getmarks(int i){
            return course[i].marks;
        }
        const float getgrade(int i){
            return course[i].grade;
        }
        ~Student(){
            cout << "Name: " << fname << ' ' << lname << endl;
            cout << "Id: " << id << endl;
            cout << "courses: " << endl;
            for(int i = 0; i<noc; i++) cout << '\t' << course[i].name << endl;
            cout << "Graduation status: ";
            willGraduate();
            cout << endl;
            cout << "Scholarship status: ";
            applyForScholarship();
            cout << endl;
            cout << "Internship status: " << endl;
            cout << "\tNumber of companies: " << noi << endl;
            cout << "\tCompany Names: " << endl;
            for(int i = 0; i<noi; i++) cout <<"\t\t"<<i+1<<". "<< companyy[i] << endl;
        }

};


int main(){
    Student s1("sadman", "ahmed", 135), s2("abubakor", "siddique", 137), s3("nazmus", "sadiq", 139);
    s1.enrollingCourses("cse 4301");
    s1.enrollingCourses("cse 4302");
    s1.enrollingCourses("cse 4303");
    s2.enrollingCourses("cse 4301");
    s2.enrollingCourses("cse 4302");
    s2.enrollingCourses("cse 4303");
    s3.enrollingCourses("cse 4301");
    s3.enrollingCourses("cse 4302");
    s3.enrollingCourses("cse 4303");
    s1.obtainedMarks("cse 4301", 85);
    s1.obtainedMarks("cse 4302", 55);
    s1.obtainedMarks("cse 4303", 75);
    s2.obtainedMarks("cse 4301", 88);
    s2.obtainedMarks("cse 4302", 75);
    s2.obtainedMarks("cse 4303", 76);
    s3.obtainedMarks("cse 4301", 82);
    s3.obtainedMarks("cse 4302", 65);
    s3.obtainedMarks("cse 4303", 95);

    s1.setGPAForEachCourse("cse 4301");
    s1.setGPAForEachCourse("cse 4302");
    s1.setGPAForEachCourse("cse 4303");
    s2.setGPAForEachCourse("cse 4301");
    s2.setGPAForEachCourse("cse 4302");
    s2.setGPAForEachCourse("cse 4303");
    s3.setGPAForEachCourse("cse 4301");
    s3.setGPAForEachCourse("cse 4302");
    s3.setGPAForEachCourse("cse 4303");
    s1.participateInInternship("cse 4301", "softech");
    s2.participateInInternship("cse 4302", "lindle");
    s1.participateInInternship("cse 4305", "bhoogle");
    s3.participateInInternship("cse 4301", "damazon");


    return 0;
}