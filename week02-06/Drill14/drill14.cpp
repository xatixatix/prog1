#include "Simple_window.h"
#include "Graph.h"

/*
g++ drill14.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o drill14 `fltk-config --ldflags --use-images`
*/

int main()
try{

using namespace Graph_lib;

//1


catch(exception&e){
	cerr<< "exception" << e.what() << '\n';
	return 1;
}
catch(...){
	cerr << "error";
	return 2;
}
