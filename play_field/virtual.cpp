#include<cmath>
#include<assert.h>

#define PI 3.1415 ;
class Shape{

	public:
		virtual double Area() const = 0;
		virtual double Perimeter() const = 0;

};

class Circle : public Shape {

	public:
		Circle (double rad) { radius_ = rad ; }
		double Area() const override { return pow(radius_, 2) * PI ; }
		double Perimeter() const override {return 2 * radius_ * PI; }	

	private:
		double radius_ ;

};


class Rectangle : public Shape {

	public:
		Rectangle(double h, double w) : height_(h), width_(w) {};
	       	double Area() const override {return height_ * width_ ;} 	
		double Perimeter() const override {return (height_ + width_) * 2; }
	private:
		double height_;
		double width_;

};


int main () {


double epsilon = 0.1 ;	
Circle circle(12.31) ;

assert(abs(circle.Area()- 77.35));
assert(abs(circle.Perimeter()- 476.06));

Rectangle rectangle(10.0,6.0) ;

assert(rectangle.Area() == 60);
assert(rectangle.Perimeter() == 32) ;
}



