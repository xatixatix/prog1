#include "std_lib_facilities.h"


template<typename T> 
struct S{

	S() {};
	S(T v) : val{v} {}

	T& get();
	const T& get() const;

	//void set(T value) {val = value;}
	S<T>& operator=(const T& v)
	{
		val= v;
		return *this;
	}

private:
	T val;
};

template<typename T>
T& S<T>::get()
{
	return val;
}

template<typename T>
const T& S<T>::get() const
{
	return val;
}


template<typename T>
void read_val(T& v)
{
	cin >> v;
	if(!cin) error("Bad input!");
}


int main()
{

	S<int> i ={2021};
	S<string> s {"Dandelion"};
	S<char> c {'c'};
	S<double> d {21.76};
	S<vector<int>> v {vector<int>{1, 2, 3, 4, 5}};

	cout << "int: "<< i.get() << endl;
	cout << "string: "<< s.get() << endl;
	cout << "char: " << c.get() << endl;
	cout << "double: " << d.get() << endl;
	cout << "vector: ";
	for(auto& a : v.get())
		cout << a << " ";
	cout << endl;

	/*
	d.set(10.10);
	cout << "\nSet double: "<< d.get() << endl;
	cout <<'\n';
	*/


	int i_read;
	cout << "Pls enter an integer: ";
	read_val(i_read);
	i = i_read;
	
	string s_read;
	cout << "Pls enter a string: ";
	read_val(s_read);
	s = s_read;
	
	char c_read;
	cout << "Pls enter a character: ";
	read_val(c_read);
	c = c_read;
	
	double d_read;
	cout << "Pls enter a double: ";
	read_val(d_read);
	d = d_read;
	cout << '\n';
	
	cout << "int: "<< i.get() << endl;
	cout << "string: "<< s.get() << endl;
	cout << "char: "<< c.get() << endl;
	cout << "double: "<< d.get() << endl;

	return 0;
}