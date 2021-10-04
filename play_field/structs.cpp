#include<iostream>
#include<cassert>

// a sturct is a just a data stricture. it can also have public and private members and invariants (logics that dictates on the value of a member variable). general guidline is struct should have all member variables as public. if not, make it a class.

struct Date{

int day;
int month;
int year;
};




int main(){

Date date;

date.day = 10;
date.month = 12;
date.year = 2021;

std::cout<< date.day <<" " << date.month << " "<< date.year << "\n";
return 0;
}
