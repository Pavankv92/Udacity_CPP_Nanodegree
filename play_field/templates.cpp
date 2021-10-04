#include<assert.h>
#include<sstream>
#include<string>

// max function returns the maximum of two arguments 
template <typename T>
T max(T a, T b) {
return a > b ? a : b ;
}


// templates allow to create generic classes
template<typename KeyType, typename ValueType>
class Mapping {
	public:
		Mapping(KeyType key, ValueType value) : key_(key), value_(value) {};
	
		std::string Print() {
			std::ostringstream stream ;
			stream << key_ << ": " << value_ ;
		return stream.str();
	
		}	
	private:
		KeyType key_ ;
		ValueType value_;

};





int main(){


// we can specify the type at the time of the initialization.
assert(max<int>(2,3) == 3) ;

//starting c++ 17, compiler can deduce the typename by itself 
//
assert(max(20.7, 30.6)== 30.6) ;

Mapping<std::string, int> map("Hello!", 20);
assert(map.Print() == "Hello!: 20") ;

}

