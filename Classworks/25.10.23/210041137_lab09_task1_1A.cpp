#include <iostream>
#include <string>
using namespace std;

enum class Material {Wood,Board,Steel,foam};
class Furniture
{
protected:
    double price;
    double discount;
    Material madeof;
    string name;
public:
    double getDiscount(){
        return price-discount;
    }
    Furniture(){
        price = 0;
        discount = 0;
    }
    void setName(string _name){
        name = _name;
    }
    string getName(){
        return name;
    }
    Furniture(double p,double d,Material m):price(0),discount(0),madeof(Material::Wood)
    {
        setPrice(p);
        setDiscount(d);
        setMadeof(m);
    }
    void setPrice(double val)
    {
        if(val>0)
            price=val;
    }
    void setDiscount(double val)
    {
        if(val<=price)
            discount=val;
    }
    void setMadeof(Material val)
    {
        madeof=val;
    }
    void setDiscountPercentage(double val){
            if(val<100 && val>0)setDiscount(val*.01);
    }
    string getMadeof()
    {
        if(madeof==Material::Wood)
            return string("Wood");
        else if(madeof==Material::Board)
            return string("Board");
        else if(madeof==Material::Steel)
            return string("Steel");
        else
            return string("");
    }
    virtual void productDetails(){
        cout << "-------------------------------------" << endl;
        cout << "Product Name: " << getName() << endl;
        cout << "Regular Price: " << price << endl;
        cout << "Discounted Price: "<< price-discount << endl;
        cout << "Material: " << getMadeof() << endl;
    };
};



enum class BedSize {Single,SemiDouble,Double};
enum class SofaSize{One,Two, Three, Four, Five};
enum class DiningTableSize{Two, Four, Six};

class Bed:public Furniture
{
    private:
        BedSize size;
    public:
        Bed(double _price, double _discount, Material _madeof, BedSize _size): size(_size){
            setPrice(_price);
            setDiscount(_discount);
            setMadeof(_madeof);
        }
        string getsize(){
            if(size == BedSize::Single) return "Single";
            else if (size == BedSize::Double) return "Double";
            else return "Semi-Double";
        }
    void productDetails()
    {
        Furniture::productDetails();
        cout << "Bed Size: " << getsize() << endl;
        cout << "#####################################" << endl;
    }
};
class Sofa:public Furniture
{
    // Furniture *f;
    private:
        SofaSize seats;
    // void a()
    // {
    //     f = new Bed();
    // }
    public:
        Sofa(double _price, double _discount, Material _madeof, SofaSize _seats): seats(_seats){
            setPrice(_price);
            setDiscount(_discount);
            setMadeof(_madeof);
        }
        string getsize(){
            if(seats == SofaSize::One) return "One";
            else if(seats == SofaSize::Two) return "Two";
            else if(seats == SofaSize::Three) return "Three";
            else if(seats == SofaSize::Four) return "Four";
            else return "Five";
        }
        void productDetails(){
            Furniture::productDetails();
            cout << "Sofa Size: " << getsize() << endl;
            cout << "#####################################" << endl;
        }

    // ~Sofa
    // {
    //     delete f;
    // }
};
class DiningTable:public Furniture
{
    private:
        DiningTableSize count;
    public:
        DiningTable(double _price, double _discount, Material _madeof, DiningTableSize _count): count(_count){
            setPrice(_price);
            setMadeof(_madeof);
            setDiscount(_discount);
        }
        string getsize(){
            if(count == DiningTableSize::Two) return "Two";
            else if(count == DiningTableSize::Four) return "Four";
            else return "Six";
        }
        void productDetails(){
            Furniture::productDetails();
            cout << "Table size: " << getsize() << endl;
            cout << "#####################################" << endl;
        }


};

/**task 4
sort_furniture_discount will sort the array in descending order based on their discount price.
You may need to add some member functions
**/
void swap(Furniture *a, Furniture *b) {
  Furniture *temp = a;
  a = b;
  b = temp;
}

void sort_furniture_discount(Furniture *furnitures[],int no_of_furnitures){
  for (int step = 0; step < no_of_furnitures-1; step++) {
    int min_idx = step;
    for (int i = step + 1; i < no_of_furnitures; i++) {
      if (furnitures[i]->getDiscount() > furnitures[min_idx]->getDiscount())
        min_idx = i;
    }
    Furniture *temp = furnitures[min_idx];
    furnitures[min_idx] = furnitures[step];
    furnitures[step] = temp;
    // swap(furnitures[min_idx], furnitures[step]);
  }
};


int main()
{
    Furniture* f_list[100];

    /**
        task 1
        So that following lines can be executed without error
    */
    f_list[0] = new Bed(10000,123,Material::Wood,BedSize::Single);
    f_list[1] = new Sofa(11000,234,Material::Steel,SofaSize::Five);
    f_list[2] = new DiningTable(13000,345,Material::Wood,DiningTableSize::Four);
    f_list[3] = new Bed(10090,123,Material::Wood,BedSize::Single);

    /**task 1 ends here*/

    /**
        task 2
        So that following lines can be executed without error

        task 3 (Modify productDetails)
    */
    f_list[2]->setDiscountPercentage(30);
    for(int i=0; i<4; i++)
    {
        f_list[i]->setName("a");
        f_list[i]->productDetails();
    }

    /**task 2 ends here*/
    /**task 3 ends here*/

    /**task 4
    So that following lines can be executed without error
    */
    sort_furniture_discount(f_list,4);
    for(int i=0; i<4; i++)
    {
        f_list[i]->productDetails();
    }
    /**task 4 ends here*/

}
