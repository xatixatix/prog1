#include "std_lib_facilities.h"

/*
g++ drill15.2.cpp -o drill15.2
*/

struct Person{
public:
	Person(){};
	Person(string nameIn, int ageIn):firstName{nameIn}, age{ageIn}{
		if (age < 0 || age > 150)
		{
			error("Bad age.\n");
		}
		if(!IsLetters(nameIn)){
			error("Only use alphabetic characters!\n");
		}
	};
	Person(string firstNameIn, string secondNameIn, int ageIn):firstName{firstNameIn}, secondName{secondNameIn}, age{ageIn}{
		if (age < 0 || age > 150)
		{
			error("Bad age.\n");
		}
		if(!IsLetters(firstNameIn) || !IsLetters(secondNameIn)){
			error("Only use alphabetic characters!\n");
		}
	};

	string getFirstName() const {return firstName;}
	string getSecondName() const {return secondName;}
	int getAge() const {return age;}

	void setFirstName(string firstNameIn){
		firstName = firstNameIn;
	}
	void setSecondName(string secondNameIn){
		secondName = secondNameIn;
	}
	void setAge(int ageIn){
		age = ageIn;
	}

	//#lopott
	bool IsLetters(string input)
	{
		for (int i = 0; i < input.size(); i++)
		{
			int uppercaseChar = toupper(input[i]);
			if (uppercaseChar < 'A' || uppercaseChar > 'Z')
			{
				return false;
			}
		}
		return true;
	}

private:
	string firstName;
	string secondName;
	int age;
};

ostream& operator<<(ostream &output, Person& p){
		output << p.getFirstName() << " is " << p.getAge() << " years old." << endl;
		return output;
	}

istream& operator>>(istream& input, Person& p){
		string fn;
		string ln;
		int ageIn;

		input >> fn;
		input >> ln;
		input >> ageIn;

		p = Person(fn, ln, ageIn);
		return input;
	}


int main()
try{

Person gof{"Goofy", 63};
cout << gof.getFirstName() << " is " << gof.getAge() << " years old." << endl;
cout << gof;

Person p;

vector<Person> Pv;

for (Person p; cin >> p;)
{
	if (p.getFirstName() != "END")
	{
		Pv.push_back(p);
	}
	else break;
}

cout << '\n';
for(Person see : Pv){
	cout << see;
}

}
catch(exception&e){
	cerr<< "exception" << e.what() << '\n';
	return 1;
}
catch(...){
	cerr << "error";
	return 2;
}
