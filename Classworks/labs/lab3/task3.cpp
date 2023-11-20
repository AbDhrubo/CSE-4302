#include<iostream>
#include<string.h>
using namespace std;

class Medicine{
    private:
        char name[25];
        char genericName[25];
        double discoutPercent = 5;
        double unitPrice = 0;
    public:
        void assignName(char nam[], char genericNam[]){
            strcpy(name, nam);
            strcpy(genericName, genericNam);
        }
        void assignPrice(double price){
            if (price>0) unitPrice = price;
            else unitPrice = 0;
        }
        void setDiscountPercent(double percent){
            if (percent <=45 && percent >=0) discoutPercent = percent; 
            else discoutPercent = 5;
        }
        double getSellingPrice(int nos){
            return nos*unitPrice*(1-.01*discoutPercent);
        }
        void display(){
            cout << name << " (" << genericName << ") has a unit price BDT "<< unitPrice<< ". Current discount " << discoutPercent << '%'<< endl;
        }
};

int main(){
    Medicine napa;
    napa.assignName("Napa", "Paracetamol");
    napa.assignPrice(12);
    napa.setDiscountPercent(23);
    cout << napa.getSellingPrice(20) << endl;
    napa.display();
    return 0;
}