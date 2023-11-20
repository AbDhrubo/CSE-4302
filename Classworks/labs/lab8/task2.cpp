#include<iostream>
using namespace std;

class Employee{
    private:
        string name;
        string emp_id;
        float salary;
        bool onDuty;
    public:
        Employee(float _salary, string _name = "Faisal Hussain", string _emp_id = "001", float _onDuty = 1) : 
        name(_name), emp_id(_emp_id), salary(_salary), onDuty(_onDuty){}
        void setName(string _name){
            name = _name;
        }
        void set_id(string _emp_id){
            emp_id = _emp_id;
        }
        void setSalary(float _salary){
            salary = _salary;
        }
        void setDuty(bool _onDuty){
            onDuty = _onDuty;
        }
        string getName(){
            return name;
        }
        string getID(){
            return emp_id;
        }
        float getSalary(){
            return salary;
        }
        bool getDuty(){
            return onDuty;
        }

};

class Manager : public Employee{
    private:
    public:
        Manager():Employee(10000){

        }
} ;

class Engineer : public Employee{
    private:
    public:
        Engineer(){
            Employee :: setSalary (8000);
        }
};

class Designer : public Employee{
    private:
    public:
        Designer(){
            Employee :: setSalary (7000);
        }
};

int main(){

}