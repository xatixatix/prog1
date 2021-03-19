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

//height width, origin and middles
constexpr int h = 600;
constexpr int w = 600;

constexpr int middlex = w/2;
constexpr int middley = h/2;

Point orig{middlex, middley};

//make window
Simple_window win{Point{50,50}, w, h, "Function graphs"};

//axis
int length = 400;
int notch = 20;
Axis xAxis {Axis::x, Point{100,300}, length, notch, "1 == 20 pixels"};
Axis yAxis {Axis::y, Point{300,500}, length, notch, "1 == 20 pixels"};
xAxis.set_color(Color::red);
yAxis.set_color(Color::red);
win.attach(xAxis);
win.attach(yAxis);

//graphs
constexpr int r_min = -10;
constexpr int r_max = 11;

constexpr int n_points = 400;
constexpr int x_scale = 20;
constexpr int y_scale = 20;

Function s{one,r_min,r_max,orig,n_points,x_scale,y_scale};
Function s2{slope,r_min,r_max,orig,n_points,x_scale,y_scale};
Function s3{square,r_min,r_max,orig,n_points,x_scale,y_scale};
Function s4{cos,r_min,r_max,orig,n_points,x_scale,y_scale};
s4.set_color(Color::blue);
Text s4Text {Point{100,385}, "x/2"};
Function s5{[](double x) {return cos(x) + slope(x);},r_min,r_max,orig,n_points,x_scale,y_scale};

win.attach(s);
win.attach(s2);
win.attach(s3);
win.attach(s4);
win.attach(s4Text);
win.attach(s5);

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
