#include <iostream>

/*
g++ drill15.2.cpp -o drill15`
*/

class Person{
	
}

int main()
try{

}
catch(exception&e){
	cerr<< "exception" << e.what() << '\n';
	return 1;
}
catch(...){
	cerr << "error";
	return 2;
}
