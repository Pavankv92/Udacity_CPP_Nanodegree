#include<assert.h>
#include<iostream>
#include<string>

// although c++ allows one to inherit from multiple classes, if we are not careful, we will run in to diamond problem : when 2 classes inherit from an abstract class and needs to override the virtual function.

class Car {
	public:
		std::string drive(){return "I'm driving"; }

};

class Boat {
	public:
		std::string cruice(){return "I'm cruicing";} 
};


class Amphibious: public Car, public Boat {};





int main(){

Car car ;
Boat boat;
Amphibious amp;

assert(amp.drive() == car.drive());
assert(amp.cruice() == boat.cruice());

}
