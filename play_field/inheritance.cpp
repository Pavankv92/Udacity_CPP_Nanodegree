#include<iostream>
#include<string>

using std::cout;
using std::string ;


class Vehicle {
	public:
		int wheels = 0 ;
		string color = "Red" ;
};


class Car : public Vehicle {

	public:
		bool sunroof = false ;

};

class Bicycle : protected Vehicle{
	public:	
		bool kickstand = false;
		void Wheels(int number ){
		
			wheels = number ;
			cout <<"number of wheels: "<< wheels<< "\n" ;
		}
};

class Scooter: private Vehicle{
	public:
		bool electric = true ;

		void Wheels(int number ){
		
		wheels = number ;

		cout <<"number of wheels: "<< wheels<< "\n" ;

		}
		
};

class Ebike : public Bicycle{

	
	//	void Wheels(int number ){
		
	//	wheels = number ;

	//	cout <<"number of wheels: "<< wheels<< "\n" ;

	//	}	

};

class Escooter : public Scooter {
	
	//	void Wheels(int number ){
		
	//	wheels = number ;

	//	cout <<"number of wheels: "<< wheels<< "\n" ;

	//	}
};


int main(){

	Car car;
	car.wheels = 4 ;
	car.color = "Red" ; // since car has a public inheritance it gives the acess to members of the base class with in main function.

	Bicycle bike ;
	cout<< bike.kickstand<< "\n" ; // can access the member function of the bicyle class
	//bike.wheels = 4 ; // since its a protectd inhenritance, Bicycle class doesnt allow access to the members of the base class from the main. 

	Scooter scoot ; 	
	cout<< scoot.electric<< "\n" ; // can access the member function of the bicyle class
	//scoot.color = "green" ; // since its a private inhenritance, Bicycle class doesnt allow access to the members of the base class from the main. 

	bike.Wheels(4); // However, protected inheritance class will be able to access members of the base class via class methods  

	scoot.Wheels(6) ; //  However, private inheritance class will be able to access members of the base class via class methods


	Ebike e ;
	e.Wheels(10) ;
	Escooter s  ; // private and public doubdle inheritance doesnt even allow class methods to access members of the base class. that is the difference between protected and prviate in first level inheritance
	
	s.Wheels(20);
	return 0;
}
