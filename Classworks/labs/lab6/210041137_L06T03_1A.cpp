#include <iostream>
#include <cmath>

using namespace std;

class Coordinate {
private:
    float abscissa;
    float ordinate;

public:
    Coordinate(float a = 0.0, float b = 0.0) : abscissa(a), ordinate(b) {}

    ~Coordinate() {}

    void display() const {
        cout << "(" << abscissa << ", " << ordinate << ")";
    }

    float getDistance(const Coordinate& a) const {
        float dx = abscissa - a.abscissa;
        float dy = ordinate - a.ordinate;
        return sqrt(dx * dx + dy * dy);
    }

    float getDistance() const {
        return sqrt(abscissa * abscissa + ordinate * ordinate);
    }

    void move_x(float a) {
        abscissa += a;
    }

    void move_y(float b) {
        ordinate += b;
    }

    void move(float a) {
        move_x(a);
        move_y(a);
    }

    bool operator>(const Coordinate& a) const {
        return getDistance() > a.getDistance();
    }

    bool operator<(const Coordinate& a) const {
        return getDistance() < a.getDistance();
    }

    bool operator>=(const Coordinate& a) const {
        return getDistance() >= a.getDistance();
    }

    bool operator<=(const Coordinate& a) const {
        return getDistance() <= a.getDistance();
    }

    bool operator==(const Coordinate& a) const {
        return abscissa == a.abscissa && ordinate == a.ordinate;
    }

    bool operator!=(const Coordinate& a) const {
        return !operator==(a);
    }

    Coordinate operator++() {
        move(1.0);
        return *this;
    }

    Coordinate operator++(int) {
        Coordinate temp(abscissa, ordinate);
        move(1.0);
        return temp;
    }

    Coordinate operator--() {
        move(-1.0);
        return *this;
    }

    Coordinate operator--(int) {
        Coordinate temp(abscissa, ordinate);
        move(-1.0);
        return temp;
    }
};

int main() {
    Coordinate c1(1.0, 1.0);
    Coordinate c2(-1.0, -1.0);
    Coordinate c3(3.0, 4.0);

    cout << "c1 > c2: " << (c1 > c2) << endl;
    cout << "c1 < c2: " << (c1 < c2) << endl;
    cout << "c1 >= c2: " << (c1 >= c2) << endl;
    cout << "c1 <= c2: " << (c1 <= c2) << endl;
    cout << "c1 == c2: " << (c1 == c2) << endl;
    cout << "c1 != c2: " << (c1 != c2) << endl;

    cout << "c3 before increment: ";
    c3.display();
    ++c3;
    cout << endl << "c3 after prefix increment: ";
    c3.display();
    --c3;
    cout << endl << "c3 after prefix decrement: ";
    c3.display();

    return 0;
}
