#include "Simple_window.h"
#include "Graph.h"

/*
g++ drill15.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o drill15 `fltk-config --ldflags --use-images`
*/

double one(double) {return 1;}
double slope(double x) {return x/2;}
double square(double x) {return x*x;}

int main()
try{

using namespace Graph_lib;



constexpr int h = 1000;
constexpr int w = 600;

constexpr int middlex = w/2;
constexpr int middley = h/2;

Point orig{middley, middlex};

constexpr int r_min = -20;
constexpr int r_max = 11;

constexpr int n_points = 400;
constexpr int x_scale = 30;
constexpr int y_scale = 30;

Simple_window win{Point{50,50}, w, h, "Function graphs"};
win.wait_for_button();

Function s{one,r_min,r_max,orig,n_points,x_scale,y_scale};
Function s2{slope,r_min,r_max,orig,n_points,x_scale,y_scale};
Function s3{square,r_min,r_max,orig,n_points,x_scale,y_scale};

win.attach(s);
win.attach(s2);
win.attach(s3);

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
