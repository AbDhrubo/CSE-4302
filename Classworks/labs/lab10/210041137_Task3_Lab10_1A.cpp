#include <iostream>
using namespace std;

class Counter {
private:
    int count;

public:
    Counter(int _count) : count(_count) {
        cout << "Constructor called. Count: " << count << endl;
    }
    
    /*Please uncomment this for making a successful copy
    Counter(const Counter& other) : count(other.count) {}

    void operator=(const Counter& other) {
        count = other.count;
        cout << "Assignment operator called. Count: " << count << endl;
    }*/

    /*Plese uncomment this for preventing a copy (will show compilation error)
    Counter(const Counter& other) = delete;

    // Delete the copy assignment operator to prevent copying
    void operator=(const Counter& other) = delete;
    */
    int getCount() const {
        return count;
    }
};

int main() {
    Counter c1(10);
    Counter c2 = c1; 
    cout << "c2 Count (Copy Initialization): " << c2.getCount() << endl;

    // Assignment Operator
    Counter c3(1);
    c3 = c1;  // This line will show compilation error without operator overloading
    cout << "c3 Count (Assignment Operator): " << c3.getCount() << endl;

    return 0;
}
