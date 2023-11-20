class CurrencyDollar {
private:
    int dollars;
    int cents;

public:
    CurrencyDollar() : dollars(0), cents(0) {}
    CurrencyDollar(int dollars, int cents) : dollars(dollars), cents(cents) {}
    int get_dollars()const {
        return dollars;
    }
    int get_cents()const {
        return cents;
    }

};

class CurrencyEuro {
private:
    int euros;
    int cents;

public:
    CurrencyEuro() : euros(0), cents(0) {}
    CurrencyEuro(int euros, int cents) : euros(euros), cents(cents) {}
    int get_euros()const {
        return euros;
    }
    int get_cents()const {
        return cents;
    }

};

class CurrencyBDT {
private:
    int taka;
    int poisha;

public:
    CurrencyBDT() : taka(0), poisha(0) {}
    CurrencyBDT(int taka, int poisha) : taka(taka), poisha(poisha) {}

    operator CurrencyDollar() const {
        double usd = (taka + poisha * 0.01) * 0.0091;
        int dollars = static_cast<int>(usd);
        int cents = static_cast<int>((usd - dollars) * 100);
        return CurrencyDollar(dollars, cents);
    }

    operator CurrencyEuro() const {
        double euro = (taka + poisha * 0.01) * 0.0085;
        int euros = static_cast<int>(euro);
        int cents = static_cast<int>((euro - euros) * 100);
        return CurrencyEuro(euros, cents);
    }
};