#include <iostream>
using namespace std;

/*
g++ drill14.cpp drill14`
*/

class B1{
public:
	virtual void vf() const {
		cout<<"B1::vf()\n";
	}

	void f() const {
		cout<<"B1::f()\n";
	}

	//virtual void pvf() const = 0;
};

class D1:public B1{
	void vf() const override { 
		cout<<"D1::vf()\n";
	}

	void f() const {
		cout<<"D1::f()\n";
	}
};

class D2:public D1{
	// void pvf() const override { 
	// 	cout<<"D2::pvf()\n";
	// }
};

void call(B1& b){
	b.vf();
	b.f();
}

int main()
try{

//1
B1 b1obj;
call(b1obj);

//2
D1 d1obj;
call(d1obj);

//3
B1& b1ref {d1obj};
call(b1ref);

/*
//6
D2 d2obj;
d2obj.f();
d2obj.vf();
d2obj.pvf();
*/

}
catch(exception&e){
	cerr<< "exception" << e.what() << '\n';
	return 1;
}
catch(...){
	cerr << "error";
	return 2;
}
