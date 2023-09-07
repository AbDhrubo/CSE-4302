#include<iostream>
using namespace std;

class Category{
    private:
        string category_name;
        int id;
        string product_name[100];
        float price[100];
        int quantity[100];
        int nop;
        float category_discount;
        float productDiscount[100];
        int getIndex(string name){
            for(int i =0; i<nop; i++){
                if(product_name[i] == name) return i;
            }
            return -1;
        }

    public:
        Category(){
            for(int i = 0; i<100; i++) price[i] = 0;
            for(int i = 0; i<100; i++) quantity[i] = 0;
            for(int i = 0; i<100; i++) productDiscount[i] = 0;
            nop = 0;
            category_discount = -1;
        }
        Category(string cat_name, int idd){
            category_name = cat_name;
            id = idd;
            category_discount = -1;
            for(int i = 0; i<100; i++) price[i] = 0;
            for(int i = 0; i<100; i++) quantity[i] = 0;
            for(int i = 0; i<100; i++) productDiscount[i] = 0;
            nop = 0;
        }
        void addToInventory(string product, int added_quantity, float p){
            product_name[nop] = product;
            price[nop] = p;
            nop ++;
        }
        void purchase(string name, int purchased_quantity){
            int idx = getIndex(name);
            if (idx == -1) cout << "product not found" << endl;
            else if(idx >=0 && quantity[idx] >= purchased_quantity) quantity[idx] -= purchased_quantity;
            else cout <<"Not enough stock" << endl;
        }
        void applyCategoryDiscount(float percent) {
            if(percent > 0 && percent <=100) category_discount = percent;
        }
        void applyProductDiscount(string name, float percent) {
            int idx = getIndex(name);
            if (idx == -1) cout << "product not found" << endl;
            else if (category_discount != -1 && percent >0 && percent <=100) productDiscount[idx] = percent;
    
        }
        int updatePrice(string name, float percent) {
            int idx = getIndex(name);
            price[idx] += price[idx] * 0.01*percent;
        }
        float displayInventoryvalue(string name){
            int idx = getIndex(name);
            if (idx == -1){
                cout << "product not found " << endl;
                return -1;
            }
            if (category_discount == -1) return price[idx] - price[idx]*0.01*productDiscount[idx];
            return price[idx] - price[idx]*0.01*category_discount ;
        }
        void totalInventoryValue(){
            if (category_discount == -1){
                float total = 0;
                for(int i = 0; i<nop; i++) total += (price[i] -price[i]*.01*productDiscount[i])* quantity[i];
                cout << "Total Value of inventory "  << total << endl;
            }
        }
        ~Category(){
            if(category_discount == -1){
                for(int i = 0; i< nop; i++){
                    cout << "Name: " << product_name[i] << ' ' << ",Price: " << price[i] - price[i]*.01*productDiscount[i]<< " ,quantity" << quantity[i] << endl; 
                }
            }
            else {
                for(int i = 0; i< nop; i++){
                    cout << "Name: " << product_name[i] << ' ' << ",Price: " << price[i] - price[i]*.01*category_discount<< " ,quantity" << quantity[i] << endl; 
                }   
            }
            
        }
};

int main(){
    Category c1, c2("chips", 101), c3("drinks", 102);
    cout << c2.displayInventoryvalue("lays") << endl;
    c2.addToInventory("lays", 70, 70);
    c2.addToInventory("pringles", 80, 250);
    c2.addToInventory("doritos", 20, 55);
    c2.applyProductDiscount("lays", 5);
    cout << c2.displayInventoryvalue("lays") << endl;
    c2.applyCategoryDiscount(7);
    c2.applyProductDiscount("pringles", 5);
    c2.purchase("doritos", 25);
    c2.purchase("doritos", 15);
    c3.addToInventory("coca cola", 200, 50);
    c3.addToInventory("pepsi", 200 , 55);
    c3.addToInventory("mountain dew", 150, 25);
    c3.updatePrice("pepsi", 33);
    c3.applyProductDiscount("pepsi", 3);
    c3.totalInventoryValue();
    return 0;
}