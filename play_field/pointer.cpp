#include<iostream>

class P{

	public : 
		P(int v) : value(v){} 
		int cal = 25 ;
		void print();
		int& print_value();
	private:
		int value ;
};


void P::print(){

    std::cout<< P::value << "\n" ;
}

// you can rturn a int when eventhough return type is int&
int& P::print_value(){
	return value ;
}


int main(){

P test(10);


P *t_point = &test ;


t_point->print();
std::cout<<t_point->cal<< "\n";
std::cout<<t_point->print_value()<< "\n";

return 0 ;
}
