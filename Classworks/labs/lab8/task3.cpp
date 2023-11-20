#include<iostream>
using namespace std;

class Address{
    private:
        string road;
        int house;
        string city;
        int zip_code;
        string district;
        string country;
    public:
        Address (string _road, int _house, string _city, int _zip_code, string _district, string _country):
        road(_road), house(_house), city(_city), zip_code(_zip_code), district(_district), country(_country){}
        Address(){}
        void setInfo(string _road, int _house, string _city, int _zip_code, string _district, string _country){
            road = _road;
            house = _house;
            city = _city;
            zip_code = _zip_code;
            district = _district;
            country = _country;
        }

};

class ContactInfo{
    private:
        string number1;
        string number2;
        string email;
    public:
        ContactInfo(string _number1, string _number2, string _email):
            number1(_number1), number2(_number2), email(_email){}
        ContactInfo(){}
        void setInfo(string _number1, string _number2, string _email){
            number1 = _number1;
            number2 = _number2;
            email = _email;
        }
        
        
};

class Employee{
    private:
        string name;
        string emp_id;
        float salary;
        bool onDuty;
        Address Present;
        Address Permanent;
        ContactInfo primary;

    public:
        Employee(string _name = "Faisal Hussain", string _emp_id = "001", float _salary = 0, float _onDuty = 1) : 
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
        void setPresent(string _road, int _house, string _city, int _zip_code, string _district, string _country){
            Present.setInfo(_road, _house, _city, _zip_code, _district, _country);
        }
        void setPermanent(string _road, int _house, string _city, int _zip_code, string _district, string _country){
            Permanent.setInfo(_road, _house, _city, _zip_code, _district, _country);
        }
        void setContact(string _number1, string _number2, string _email){
            primary.setInfo(_number1, _number2, _email);
        }
};

int main(){

}