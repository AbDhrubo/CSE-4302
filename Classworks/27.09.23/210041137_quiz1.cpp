#include<iostream>
using namespace std;

class Employee{
    private:
        string name;
        string title;
        int salary;
        static int no_of_employees;
    public:
        Employee(string n, string t, int s): name(n), title(t), salary(s){
            no_of_employees++;
        }  
        Employee (){
            name = "not_set";
            title = "not_set";
            salary = -1;
            no_of_employees++;
        }  
        int get_salary() const{
            return salary;
        }   
        string get_name() const{
            return name;
        }
        string get_title() const{
            return title;
        }
        void set_name(string n){
            name = n;
        }
        void set_title(string t){
            title = t;
        }
        void set_salary(int s){
            salary = s;
        }
        int annual_salary(){
            return salary*12;
        }
        int total_employees(){
            return no_of_employees;
        }
        bool operator>(Employee e){
            return annual_salary() > e.annual_salary();
        }
};


class SalaryCalculator{
    private:
    public:
        friend int ann_s();
        int annual_salary(Employee e){
            return e.get_salary()*12;
        }
};
void display(Employee e[], int count){
    for(int i = 0; i<count; i++){
        cout << "Employee " << i+1 << ":" << endl;
        cout << "\tName: " << e[i].get_name() << ", Title: " << e[i].get_title() << ", Monthly Salary: " << e[i].get_salary() << ", Annual Salary: "<< e[i].annual_salary() << endl; 
    }
    cout << "Total number of employees: " << e[4].total_employees();
}

void sort(Employee arr[], int count){
    for(int i = 0; i<count; i++){
        for(int j = i+1; j<count; j++){
            if(arr[i] > arr[j]) swap(arr[i], arr[j]);
        }
    }
}

int Employee::no_of_employees = 0;

int main(){
    Employee arr[5]
    ;
    for(int i = 0; i<5; i++){
        cout << "Name: "<< endl;
        string n,t;
        int s;
        cin >> n;
        cout << "Title: " << endl;
        cin >> t;
        cout << "Salary: " << endl;
        cin >> s;
        arr[i].set_name(n);
        arr[i].set_title(t);
        arr[i].set_salary(s);        
    }
    sort(arr, 5);
    display(arr, 5);
}