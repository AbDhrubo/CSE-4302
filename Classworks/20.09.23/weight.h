#include<iostream>
using namespace std;
class Weight{
    private: 
        const double kgToPound = 2.2;
        int pound;
        double ounce;
    public:
        Weight(){
            pound = 0;
            ounce = 0;
        }
        Weight(double kg) {
            pound = static_cast<int> (kg*kgToPound);
            ounce = (kg * kgToPound - pound) * 16.0;
        }
        Weight(int pound, double ounce) : pound(pound), ounce(ounce) {}
        void showWeight(){
            cout << "The weight is: "<< pound <<" pound " << ounce << " ounce." << endl;
        }
        operator double() const {
            return static_cast<double>(pound) / kgToPound + ounce / (kgToPound * 16.0);
        }
};