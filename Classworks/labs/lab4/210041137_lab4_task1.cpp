#include<iostream>
using namespace std;
enum type{
    Current,
    Savings
};
class BankAccount{
    private:
        int acc_num;
        string acc_name;
        type acc_type;
        float cur_bal;
        float min_bal;
    public:
        BankAccount(int num, string name, type t, float c, float m){
            acc_num = num;
            acc_name = name;
            acc_type = t;
            cur_bal = c;
            min_bal = m;
        }
        void set_acc_num(int x){
            acc_num = x;
        }
        void set_acc_name (string s){
            acc_name = s;
        }
        void set_type(type t){
            acc_type = t;
        }
        void set_curb(float f){
            cur_bal = f;
        }
        void set_minb(float f){
            min_bal = f;
        }
        void display(){
            cout << "Account Number: " << acc_num << endl;
            cout << "Account Name: " << acc_name << endl;
            cout << "Account type: ";
            if (acc_type) cout << "Savings" << endl;
            else cout << "Current" << endl;
            cout << "Current Balance: " << cur_bal << endl;
            cout << "Minimum Balance: " << min_bal << endl;
        }
        void showBalance(){
            cout << "Current Balance: " << cur_bal << endl;
        }
        void deposit(float f){
            if(cur_bal+f <min_bal) cout << "Invalid amount" << endl;
            else cur_bal += f;
            showBalance();
        }
        void withdrawal(float f){
            if(cur_bal -f <min_bal) cout << "Inavlid amount" << endl;
            else cur_bal -= f;
            showBalance();
        }

        void giveInterest(float interest = 3){
            interest -= interest*0.1;
            deposit(interest*cur_bal*0.01);
            showBalance();
        }
        ~BankAccount(){
            cout << "Account of " << acc_name << " with account no "<< acc_num << " is destroyed with a balance BDT " << cur_bal<< endl;
        }
};

int main(){
    BankAccount a(1101, "dhrubo", Current, 12000, 500);
    a.display();
    BankAccount b(1102, "abu bakor", Current, 14000, 500);
    b.display();
    a.deposit(2000);
    b.withdrawal(13600);
    a.giveInterest(2.5);
    b.giveInterest();
    return 0;
}