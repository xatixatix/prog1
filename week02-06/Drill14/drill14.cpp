#include "Simple_window.h"

/*
g++ drill14.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o drill14 `fltk-config --ldflags --use-images`
*/

class B1{
public:
	virtual void vf(){
		cout<<"B1::vf()\n";
	}

	void f(){
		cout<<"B1::f()\n";
	}

	virtual void pvf() = 0;
};

class D1:B1{
public:
	void vf() override { 
		cout<<"D1::vf()\n";
	}

	void f(){
		cout<<"D1::f()\n";
	}
};

class D2:D1{
public:
	void pvf() override { 
		cout<<"D2::pvf()\n";
	}
};

int main()
try{
/*
//1
B1 b1obj;
b1obj.vf();
b1obj.f();

//2
D1 d1obj;
d1obj.vf();
d1obj.f();

//3
B1& b1ref {d1obj};
*/

//6
D2 d2obj;
d2obj.f();
d2obj.vf();
d2obj.pvf();

}
catch(exception&e){
	cerr<< "exception" << e.what() << '\n';
	return 1;
}
catch(...){
	cerr << "error";
	return 2;
}
