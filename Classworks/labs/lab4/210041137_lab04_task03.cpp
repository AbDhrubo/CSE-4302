#include<iostream>
#include<cmath>
using namespace std;

class Rectangle{
    private:
        float length;
        float width;
    public: 
        Rectangle(float l = 1, float w = 1){
            set_len(l);
            set_wid(w);
        }
        void display()
        {
            cout << "length = " << length << ", width = " << width << endl;
        }
        void set_len(float l){
            if(l>=1 && l<20) length = l;
            else{
                cout << "Inavlid length, legth set to default value" << endl;
                length = 1;
            } 
        }
        void set_wid(float w){
            if(w>=1 && w<20) width = w;
            else{
                cout << "Invalid width, width set to default value" << endl;
                width = 1;
            } 
        }
        float perimeter(){
            return 2*(length+width);
        }
        float area(){
            return length*width;
        }
        float diagonal(){
            return sqrt(length*length+ width*width);
        }
        float angle(){
            return 180*atan(length/width)/3.14159;
        }
};

int main(){
    Rectangle a(4,5);
    a.display();
    Rectangle b;
    b.display();
    Rectangle c(0, 25);
    cout << "area = " << a.area() << endl;
    cout << "perimeter = " << a.perimeter() << endl;
    cout << "diagonal = " << a.diagonal() << endl;
    cout << "angle = " << a.angle() << endl;
    return 0;
}