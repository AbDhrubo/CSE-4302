#include <iostream>
using namespace std;

class MyClass {
private:
    int data;

public:
    MyClass(int d) : data(d) {}

    // Static member function
    static void staticFunction() {
        cout << "This is a static member function." << endl;
    }
    // Non-static member function
    void displayData() {
        cout << "Data: " << data << endl;
    }
};

int main() {
    MyClass obj1(42);
    MyClass obj2(55);

    // Calling the static member function using the class name
    MyClass::staticFunction();

    // Calling a non-static member function through an instance
    obj1.displayData();
    obj2.displayData();
    obj1.staticFunction();
    return 0;
}

