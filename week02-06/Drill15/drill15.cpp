#include "Simple_window.h"
#include "Graph.h"

/*
g++ drill15.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o drill15 `fltk-config --ldflags --use-images`
*/

int main()
try{

using namespace Graph_lib;

constexpr int h = 1000;
constexpr int w = 600;

constexpr int middlex = w/2;
constexpr int middley = h/2;

Point orig{middley, middlex};

Simple_window win{Point{50,50}, w, h, "Function graphs"};
win.wait_for_button();

}
catch(exception&e){
	cerr<< "exception" << e.what() << '\n';
	return 1;
}
catch(...){
	cerr << "error";
	return 2;
}
