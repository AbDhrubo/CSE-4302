#include <iostream>

using namespace std;

class Counter {
private:
    int count;
    int incrementStep;

public:
    Counter(int initialCount = 0, int initialStep = 1) {
    if (initialCount < 0) count = 0;
    else count = initialCount;
    if (initialStep < 1) incrementStep = 1;
    else incrementStep = initialStep;
    }

    void setIncrementStep(int step_val) {
        if (step_val > 0) {
            incrementStep = step_val;
        }
    }

    int getCount() const {
        return count;
    }
    int getIncrementStep(){
        return incrementStep;
    }

    void increment() {
        count += incrementStep;
    }

    void resetCount() {
        count = 0;
    }

    Counter operator+(const Counter& c2) const {
        Counter result(count + c2.count, max(incrementStep, c2.incrementStep));
        return result;
    }

    bool operator>(const Counter& c2) const {
        return count > c2.count;
    }

    bool operator<(const Counter& c2) const {
        return count < c2.count;
    }

    bool operator>=(const Counter& c2) const {
        return count >= c2.count;
    }

    bool operator<=(const Counter& c2) const {
        return count <= c2.count;
    }

    bool operator==(const Counter& c2) const {
        return count == c2.count;
    }

    bool operator!=(const Counter& c2) const {
        return count != c2.count;
    }

    Counter& operator+=(const Counter& c2) {
        count += c2.count;
        incrementStep = max(incrementStep, c2.incrementStep);
        return *this;
    }

    Counter operator++(int) {
        Counter temp(*this);
        count += incrementStep;
        return temp;
    }

    Counter& operator++() {
        count += incrementStep;
        return *this;
    }
};

int main() {
    Counter c1(5, 2);
    Counter c2(7, 3);
    Counter c3(10, 4);

    c1 = c2 + c3;
    cout << "c1.count = " << c1.getCount() << ", c1.incrementStep = " << c1.getIncrementStep() << endl;

    if (c1 > c2) {
        cout << "c1 > c2." << endl;
    }

    c1 += c2;
    cout << "c1.count = " << c1.getCount() << ", c1.incrementStep = " << c1.getIncrementStep() << endl;

    Counter c4 = c2++;
    cout << "c4.count = " << c4.getCount() << ", c2.count = " << c2.getCount() << endl;

    Counter c5 = ++c3;
    cout << "c5.count = " << c5.getCount() << ", c3.count = " << c3.getCount() << endl;

    return 0;
}
