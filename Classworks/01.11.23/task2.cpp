#include <iostream>
#include <string>
using namespace std;

enum class Material { Wood, Board, Steel, Foam };

class Furniture {
protected:
    double price;
    double discount;
    Material madeof;
    string name;

public:
    double getDiscount() {
        return price - discount;
    }

    Furniture() {
        price = 0;
        discount = 0;
    }

    void setName(string _name) {
        name = _name;
    }

    string getName() {
        return name;
    }

    Furniture(double p, double d, Material m) : price(0), discount(0), madeof(Material::Wood) {
        setPrice(p);
        setDiscount(d);
        setMadeof(m);
    }

    void setPrice(double val) {
        if (val > 0)
            price = val;
    }

    void setDiscount(double val) {
        if (val <= price)
            discount = val;
    }

    void setMadeof(Material val) {
        madeof = val;
    }

    void setDiscountPercentage(double val) {
        if (val < 100 && val > 0)
            setDiscount(price * val * 0.01);
    }

    string getMadeof() {
        if (madeof == Material::Wood)
            return "Wood";
        else if (madeof == Material::Board)
            return "Board";
        else if (madeof == Material::Steel)
            return "Steel";
        else
            return "";
    }

    // Implementation of virtual function
    virtual void productDetails() {
        cout << "-------------------------------------" << endl;
        cout << "Product Name: " << getName() << endl;
        cout << "Regular Price: " << price << endl;
        cout << "Discounted Price: " << price - discount << endl;
        cout << "Material: " << getMadeof() << endl;
    }

    virtual void productCount() = 0;

    // Overload the << operator to print the name of the furniture
    friend ostream& operator<<(ostream& os, const Furniture& furniture) {
        os << "Name: " << furniture.name;
        return os;
    }
};

enum class BedSize { Single, SemiDouble, Double };
enum class SofaSize { One, Two, Three, Four, Five };
enum class DiningTableSize { Two, Four, Six };

class Bed : public Furniture {
private:
    BedSize size;
    static int count;

public:
    Bed(double _price, double _discount, Material _madeof, BedSize _size) : size(_size) {
        setPrice(_price);
        setDiscount(_discount);
        setMadeof(_madeof);
        count++;
    }

    string getsize() {
        if (size == BedSize::Single) return "Single";
        else if (size == BedSize::Double) return "Double";
        else return "Semi-Double";
    }

    void productDetails() {
        Furniture::productDetails();
        cout << "Bed Size: " << getsize() << endl;
        cout << "#####################################" << endl;
    }

    void productCount() {
        cout << "There are a total of " << count << " beds." << endl;
    }
};

// Initialize the static member variable count
int Bed::count = 0;

class Sofa : public Furniture {
private:
    SofaSize seats;
    static int count;

public:
    Sofa(double _price, double _discount, Material _madeof, SofaSize _seats) : seats(_seats) {
        setPrice(_price);
        setDiscount(_discount);
        setMadeof(_madeof);
        count++;
    }

    string getsize() {
        if (seats == SofaSize::One) return "One";
        else if (seats == SofaSize::Two) return "Two";
        else if (seats == SofaSize::Three) return "Three";
        else if (seats == SofaSize::Four) return "Four";
        else return "Five";
    }

    void productDetails() {
        Furniture::productDetails();
        cout << "Sofa Size: " << getsize() << endl;
        cout << "#####################################" << endl;
    }

    void productCount() {
        cout << "There are a total of " << count << " sofas." << endl;
    }
};

// Initialize the static member variable count
int Sofa::count = 0;

class DiningTable : public Furniture {
private:
    DiningTableSize count;
    static int num;

public:
    DiningTable(double _price, double _discount, Material _madeof, DiningTableSize _count) : count(_count) {
        setPrice(_price);
        setMadeof(_madeof);
        setDiscount(_discount);
        num++;
    }

    string getsize() {
        if (count == DiningTableSize::Two) return "Two";
        else if (count == DiningTableSize::Four) return "Four";
        else return "Six";
    }

    void productDetails() {
        Furniture::productDetails();
        cout << "Table size: " << getsize() << endl;
        cout << "#####################################" << endl;
    }

    void productCount() {
        cout << "There are a total of " << num << " dining tables." << endl;
    }
};

// Initialize the static member variable num
int DiningTable::num = 0;

void sort_furniture_discount(Furniture* furnitures[], int no_of_furnitures) {
    for (int step = 0; step < no_of_furnitures - 1; step++) {
        int min_idx = step;
        for (int i = step + 1; i < no_of_furnitures; i++) {
            if (furnitures[i]->getDiscount() > furnitures[min_idx]->getDiscount())
                min_idx = i;
        }
        Furniture* temp = furnitures[min_idx];
        furnitures[min_idx] = furnitures[step];
        furnitures[step] = temp;
    }
}

int main() {
    Furniture* f_list[100];

    f_list[0] = new Bed(10000, 123, Material::Wood, BedSize::Single);
    f_list[1] = new Sofa(11000, 234, Material::Steel, SofaSize::Five);
    f_list[2] = new DiningTable(13000, 345, Material::Wood, DiningTableSize::Four);
    f_list[3] = new Bed(10090, 123, Material::Wood, BedSize::Single);

    f_list[2]->setDiscountPercentage(30);

    f_list[0]->setName("A");
    f_list[1]->setName("B");
    f_list[2]->setName("C");
    f_list[3]->setName("D");

    for (int i = 0; i < 4; i++) {
        f_list[i]->productDetails();
        f_list[i]->productCount();
    }

    sort_furniture_discount(f_list, 4);

    for (int i = 0; i < 4; i++) {
        f_list[i]->productDetails();
    }

    // Overload the << operator to print the name of the furniture
    for (int i = 0; i < 4; i++) {
        cout << *f_list[i] << endl;
    }

    return 0;
}
