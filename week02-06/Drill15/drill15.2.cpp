#include "std_lib_facilities.h"

/*
g++ drill15.2.cpp -o drill15.2
*/

struct Person{
public:
	Person(string nameIn, int ageIn):firstName{nameIn}, age{ageIn}{};
	Person(string firstNameIn, string secondNameIn, int ageIn):firstName{firstNameIn}, secondName{secondNameIn}, age{ageIn}{};

	string getFirstName() const {return firstName;}
	string getSecondName() const {return secondName;}
	int getAge() const {return age;}

private:
	string firstName;
	string secondName;
	int age;
};

int main()
try{

Person gof{"Goofy", 63};
cout << gof.getFirstName() << " is " << gof.getAge() << " years old." << endl;

}
catch(exception&e){
	cerr<< "exception" << e.what() << '\n';
	return 1;
}
catch(...){
	cerr << "error";
	return 2;
}
