#include<iostream>
using namespace std;

class Shape{
    private:
        double area;
    public:
        void setArea(double a){
            area = a;
        }
        Shape(double a = 0): area(a){}
        double getArea(){
            return area;
        }

};

class TwoDimensionalShape : protected Shape{
    private:
        double perimeter;
    public:
        void setPerim(double _perim){
            perimeter = _perim;
        }
        TwoDimensionalShape(double _perim = 0) : perimeter (_perim){}
        double getPerimeter(){
            return perimeter;
        }
        void whoAmI(){
            cout << "I am a two dimensional shape" << endl;
        }
};

class ThreeDimensionalShape : public Shape{
    private:
        double volume;
    public:
        void setVolume(double _volume){
            volume  = _volume;
        }
        ThreeDimensionalShape(double _volume = 0) : volume(_volume){}
        void whoAmI(){
            cout << "I am a three dimensional shape" << endl;
        }
        double getVolume(){
            return volume;
        }
};

class Circle : public TwoDimensionalShape{
    private:
        double radius;
    public:
        void setRad(double _radius){
            radius = _radius;
            
        }
        Circle(double _radius = 0) : radius(_radius){
            setArea(3.14 * radius* radius);
            setPerim(2* 3.14 * radius);
        }
        void whoAmI(){
            TwoDimensionalShape :: whoAmI();
            cout << "I am a Circle with \nRadius = " << radius << endl << "Area = " << Shape :: getArea() <<endl << "Perimeter = " << TwoDimensionalShape :: getPerimeter() << endl;   
        }
};

class Square : public TwoDimensionalShape{
    private:
        double side;
    public:
        void setSide(double _side) {
            side = _side;
            setArea(side*side);
            setPerim(4*side);
        }
        Square(double _side = 0): side(_side){
            setArea(side*side);
            setPerim(4*side);
        }
        Square(): side(0){
            setArea(0);
            setPerim(0);
        }
        void whoAmI(){
            TwoDimensionalShape :: whoAmI();
            cout << "I am a Square with \nSide = " << side << endl << "Area = " << Shape :: getArea() <<endl << "Perimeter = " << TwoDimensionalShape :: getPerimeter() << endl;   
        }
};

class Rectangle : public TwoDimensionalShape{
    private:
        double length;
        double width;
    public:
        void setDimesion(double _length, double _width){
            length = _length;
            width = _width;
            setArea(length*width);
            setPerim(2*(length+width));
        }
        Rectangle(double _length = 0, double _width = 0): length(_length), width(_width){
            setArea(length*width);
            setPerim(2*(length+width));
        }
        Rectangle(): length(0), width(0){
            setArea(0);
            setPerim(0);
        }
        void whoAmI(){
            TwoDimensionalShape :: whoAmI();
            cout << "I am a Rectangle with \nLength = " << length<<"\nWidth = " << width << endl << "Area = " << Shape :: getArea() <<endl << "Perimeter = " << TwoDimensionalShape :: getPerimeter() << endl;   
        }
};

class Cube : public ThreeDimensionalShape{
    private:
        double side;
    public:
        Cube(double _side = 0): side(_side){
            setArea(side*side);
            setVolume(side*side*side);
        }
        Cube(): side(0){
            setArea(0);
            setVolume(0);
        }
        void setSide(double _side) {
            side = _side;
            setArea(side*side);
            setVolume(side*side*side);
        }
        void whoAmI(){
            ThreeDimensionalShape :: whoAmI();
            cout << "I am a Cube with \nSide = " << side << endl << "Area = " << Shape :: getArea() <<endl << "Volume = " << ThreeDimensionalShape :: getVolume() << endl;   
        }
};

class Sphere: public ThreeDimensionalShape{
    private:
        double radius;
    public:
        Sphere(double _radius = 0): radius(_radius){
            setArea(4.0*3.14*radius*radius);
            setVolume(1.3333*3.1416*radius * radius * radius);
        }
        Sphere(){
            radius = 0;
            setArea(4.0*3.14*radius*radius);
            setVolume(1.3333*3.1416*radius * radius * radius);
        }
        void setRad(double _radius){
            radius = _radius;
            setArea(4.0*3.14*radius*radius);
            setVolume(1.3333*3.1416*radius * radius * radius);
        }
        void whoAmI(){
            ThreeDimensionalShape :: whoAmI();
            cout << "I am a Sphere with \nRadius = " << radius << endl << "Area = " << Shape :: getArea() <<endl << "Volume = " << ThreeDimensionalShape :: getVolume() << endl;
        }
};

class Cylindar: public ThreeDimensionalShape{
    private:
        double height;
        double radius;
    public:
        Cylindar(double _radius = 0, double _height = 0): radius(_radius), height(_height){
            setArea(3.1416* radius* radius);
            setVolume(3.14 *radius*radius*height);
        }
        Cylindar(): radius(0), height(0){
            setArea(3.1416* radius* radius);
            setVolume(3.14 *radius*radius*height);
        }
        void setDimension(double _radius, double _height){
            radius = _radius;
            height = _height;
            setArea(3.1416* radius* radius);
            setVolume(3.14 *radius*radius*height);
        }
        void whoAmI(){
            ThreeDimensionalShape :: whoAmI();
            cout << "I am a Cylindar with \nheight = " << height<<"\nRadius = " << radius << endl << "Area = " << Shape :: getArea() <<endl << "Volume = " << ThreeDimensionalShape :: getVolume() << endl;   
        }
};

int main(){
    Square s1(4);
    Circle c1(5);
    Cylindar cy(4,5);
    s1.whoAmI();
    c1.whoAmI();
    cy.whoAmI();
    return 0;
}