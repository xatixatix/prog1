#include "std_lib_facilities.h"

/*
g++ ch17.cpp -o ch17
*/

int main()
try{

	char c = 'a';
	char* cp = &c;

	int i = 100;
	int* ip = &i;

	bool b = true;
	bool* bp = &b;

	double d = 2.3232333;
	double* dp = &d;

	cout << "The size of char is: " << sizeof(char) << "\nThe size of char* is: " << sizeof(cp) << endl;
	cout << "The size of int is: " << sizeof(int) << "\nThe size of int* is: " << sizeof(ip) << endl;
	cout << "The size of bool is: " << sizeof(bool) << "\nThe size of bool* is: " << sizeof(bp) << endl;
	cout << "The size of double is: " << sizeof(double) << "\nThe size of double* is: " << sizeof(dp) << endl;

}
catch(exception&e){
	cerr<< "exception" << e.what() << '\n';
	return 1;
}
catch(...){
	cerr << "error";
	return 2;
}
