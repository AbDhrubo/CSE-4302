// You need to implement a `Weight` class where you can convert Weight
// to double and double to Weight.
// It has three member variables:
// kgToPound: A constant double representing the conversion factor
// from KG to Pound
// pound: An integer variable to store the number of pounds in the
// Weight class.
// ounce: A double variable to store the decimal number in the Weight
// class.
// The class provides the following member functions:
// Weight()
// Weight(double kg): converts it to pound and ounce.
// Weight(int pound, double ounce): sets the Weight accordingly.
// showWeight(): Displays the weight in the format pound-ounce.
// A conversion operator operator double() that converts a Weight
// object to kg.
#include<bits/stdc++.h>
#include "weight.h"
using namespace std;


int main(){

    Weight weight_kg(57.0);
    weight_kg.showWeight();

    double weight_in_kg = weight_kg;
    cout << "Weight in KG: " << weight_in_kg << endl;
    Weight weight_lb(150, 8.5);
    weight_lb.showWeight();

    weight_in_kg = weight_lb;
    cout << "Weight in KG: " << weight_in_kg << endl;
}