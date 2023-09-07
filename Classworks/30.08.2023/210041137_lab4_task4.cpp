#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Product {
private:
    string name;
    string id;
    double price;
    int quantity;
    int max_quantity;
    bool available;

public:
    Product() : name(""), id(""), price(0), quantity(0), max_quantity(0), available(false) {}
    Product(string name, string id, double price = 0, int quantity = 0) : name(name), id(id), price(price), quantity(quantity), max_quantity(0), available(false) {}

    string getName() const {
        return name;
    }

    void setName(string name) {
        this->name = name;
    }

    string getId() const {
        return id;
    }

    void setId(string id) {
        this->id = id;
    }

    double getPrice() const {
        return price;
    }

    void setPrice(double price) {
        this->price = price;
    }

    int getQuantity() const {
        return quantity;
    }

    void setQuantity(int quantity) {
        this->quantity = quantity;
    }

    void setMaxQuantity(int qty) {
        max_quantity = qty;
    }

    void addToInventory(int added_quantity) {
        if (quantity + added_quantity <= max_quantity) {
            quantity += added_quantity;
        } else {
            cout << "Cannot add more items than the maximum allowed." << endl;
        }
    }

    bool isAvailable() {
        available = quantity > 0;
        return available;
    }

    void purchase(int purchased_quantity) {
        if (isAvailable() && purchased_quantity <= quantity) {
            quantity -= purchased_quantity;
            cout << "Purchased " << purchased_quantity << " " << name << "(s)." << endl;
        } else {
            cout << "Product not available or insufficient quantity." << endl;
        }
    }

    double updatePrice(int percent) {
        price += (price * percent) / 100;
        return price;
    }

    void displayInventoryValue() {
        double inventoryValue = quantity * price;
        cout << "Inventory value of " << name << ": $" << fixed << setprecision(2) << inventoryValue << endl;
    }

    void displayDetails() {
        cout << "Product Name: " << name << endl;
        cout << "Product ID: " << id << endl;
        cout << "Price: $" << fixed << setprecision(2) << price << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Max Quantity: " << max_quantity << endl;
        cout << "Available: " << (available ? "Yes" : "No") << endl;
    }

    ~Product() {
        cout << "Product " << name << " with ID " << id << " has been removed from inventory." << endl;
    }
};

int main() {
    Product product1("Item 1", "ID001", 10, 50);
    Product product2("Item 2", "ID002", 20, 30);
    Product product3("Item 3", "ID003", 15, 40);

    product1.setMaxQuantity(100);
    product2.setMaxQuantity(50);
    product3.setMaxQuantity(75);

    product1.addToInventory(20);
    product2.addToInventory(40);
    product3.addToInventory(25);

    cout << "Is " << product1.getName() << " available? " << (product1.isAvailable() ? "Yes" : "No") << endl;
    cout << "Is " << product2.getName() << " available? " << (product2.isAvailable() ? "Yes" : "No") << endl;
    cout << "Is " << product3.getName() << " available? " << (product3.isAvailable() ? "Yes" : "No") << endl;

    product1.purchase(15);
    product2.purchase(35);
    product3.purchase(20);

    product1.updatePrice(5);
    product2.updatePrice(-10);

    product1.displayDetails();
    product2.displayDetails();
    product3.displayDetails();

    product1.displayInventoryValue();
    product2.displayInventoryValue();
    product3.displayInventoryValue();

    double totalInventoryValue = (product1.getQuantity() * product1.getPrice()) +
                                 (product2.getQuantity() * product2.getPrice()) +
                                 (product3.getQuantity() * product3.getPrice());

    cout << "Total Inventory Value: $" << fixed << setprecision(2) << totalInventoryValue << endl;

    return 0;
}