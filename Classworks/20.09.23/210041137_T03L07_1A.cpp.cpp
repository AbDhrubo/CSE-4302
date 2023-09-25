#include <iostream>
#include "currency.h"
using namespace std;

int main() {
    CurrencyBDT bdtAmount(5545, 50);
    CurrencyDollar dollarAmount = bdtAmount;
    cout << "In USD: $" << dollarAmount.get_dollars() << "." << dollarAmount.get_cents() << endl;
    CurrencyEuro euroAmount = bdtAmount;
    cout << "In Euro: " << euroAmount.get_euros() << "." << euroAmount.get_cents() << " Euro" << endl;

    return 0;
}
