#include<iostream>
using namespace std;

class Medicine{
    private:
        string name;
        string genericName;
        double discountPercent;
        double unitPrice;
        int checkpercent(double x){
            if(x>=0 && x<=45) return 1;
            else return 0;
        } 
        double noi;  
        double inventoryPrice;
        double original_price;

    public:
        Medicine(){
           unitPrice = 0;
           discountPercent = 5;
           noi = 0; 
           inventoryPrice = 0;
           original_price = 0;
        }
        Medicine(string n, string g, double p ){
            name = n;
            unitPrice = p;
            genericName = g;
            discountPercent = 5;
            noi = 0;
            inventoryPrice = 0;
            original_price = p;
        }
        void addToInventory(int x){
            noi += x;
            inventoryPrice += unitPrice*x;
        }
        double updatedPrice(int percent){
            if(checkpercent(percent)) {
                unitPrice- unitPrice*.01*percent;
                return unitPrice;
            }
        }
        double getsellingPrice(int nos){
            if(nos <= noi){
                noi -= nos;
                inventoryPrice -= nos*(unitPrice-unitPrice*.01*discountPercent);
                return nos*(unitPrice-unitPrice*.01*discountPercent);
            }
            else cout << "not enough stock" << endl;
        }
        double readjustPrice(){
            return inventoryPrice/noi;
        }
        void resetPrice(){
            unitPrice = original_price;
        }
        ~Medicine(){
            cout << "Name: " << name << endl;
            cout << "Generic Name: " << genericName << endl;
            cout << "Unit price: " << unitPrice << endl;
            cout << "Discount percentage: " << discountPercent << endl;
        }
};  

int main(){
    Medicine m1("napa", "paracetamol", 1.2), m2 ("alatrol" ,"Cetirizine dihydrochloride", 4.5), m3("tamiflu", "oseltamivir", 34);
    m1.addToInventory(500);
    cout << m1.getsellingPrice(100) << endl;
    cout << m1.readjustPrice() << endl;
    m1.updatedPrice(10);
    cout << m1.getsellingPrice(50) << endl;
    cout << m1.readjustPrice() << endl;
    m1.resetPrice();
    cout << m1.getsellingPrice(30) << endl;
    cout << m1.readjustPrice() << endl;
    return 0;
}