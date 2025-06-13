/*Define a base class `Shape` with private attributes `color` and `area`.
 Implement public member functions for setting and getting the color and calculating the area. 
 Derive two classes, `Circle` and `Rectangle`, from the `Shape` class. 
 Implement methods to calculate the area specific to each shape. 
Demonstrate abstraction by calling the area calculation methods for both `Circle` and `Rectangle`.*/

#include <iostream>
using namespace std;

class Shape {
private:
    string color;
    int area;

public:
    Shape() : color("undefined"), area(0) {}

    void setColor(const string& c) {
        color = c;
    }

    string getColor() const {
        return color;
    }

    int getArea() const {
        return area;
    }

    void setArea(int a) {
        area = a;
    }

    virtual void calculateArea() = 0; 

   
};

class Circle : public Shape 
{
private:
    int radius;

public:
    Circle() : radius(0) {}

    void setRadius(int r) 
	{
        radius = r;
    }

    void calculateArea() 
	 {
        const int PI = 3.14;
        int a = PI * radius * radius;
        setArea(a);
    }
};

class Rectangle : public Shape
 {
private:
    int width;
    int height;

public:
    Rectangle() : width(0), height(0) {}

    void setWidth(int w) {
        width = w;
    }

    void setHeight(int h) {
        height = h;
    }

    void calculateArea() 
	 {
        int a = width * height;
        setArea(a);
    }
};

int main()
 {
    Circle circle;
    circle.setColor("yellow");
    circle.setRadius(5.0);

    Rectangle rectangle;
    rectangle.setColor("pink");
    rectangle.setWidth(4.0);
    rectangle.setHeight(6.0);

    Shape* shapes[2] = { &circle, &rectangle };

    for (int i = 0; i < 2; ++i) {
        shapes[i]->calculateArea();
        cout << "Shape color: " << shapes[i]->getColor() << endl;
        cout << "Area: " << shapes[i]->getArea() << endl;
       
    }

 
}
/*output:
Shape color: yellow
Area: 75
Shape color: pink
Area: 24
*/
