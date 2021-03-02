#include "Simple_window.h"
#include "Graph.h"

/*
g++ drill12.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o drill12 `fltk-config --ldflags --use-images`
*/

int main()
try{

using namespace Graph_lib;

Point tl{50,50};
Simple_window win{tl, 600, 400, "My window"};
win.wait_for_button();

Polygon poly;
poly.add(Point{210,200});
poly.add(Point{320,100});
poly.add(Point{320,200});
win.set_label("Haromszog");
win.attach(poly);
win.wait_for_button();

//Axis
Axis xa{Axis::x, Point(50,320), 220, 12, "x.axis"};

 win.attach(xa);
 win.set_label("X tengely");
 win.wait_for_button();

 Axis yax{Axis::y, Point(50,320), 220, 12, "y.axis"};
 yax.set_color(Color::green);
 yax.label.set_color(Color::yellow);
 win.attach(yax);
 win.set_label("Y tengely");
 win.wait_for_button();


//Function
Function sine(sin,0,50,Point{50,320}, 500,30,30);
win.attach(sine);
win.set_label("Sin fuggveny");
win.wait_for_button();
sine.set_color(Color::green);

//Polygons
Polygon poly2;
poly2.add(Point{300,300});
poly2.add(Point{350,100});
poly2.add(Point{400,300});
poly2.set_color(Color::green);
poly2.set_style(Line_style::dash);
win.attach(poly2);
win.set_label("Nagy haromszog");
win.wait_for_button();

//Rectangle
Rectangle r{Point{125,125}, 80,28};
win.attach(r);
win.set_label("Teglalap");
win.wait_for_button();

Closed_polyline poly_rect;
poly_rect.add(Point{100,50});
poly_rect.add(Point{200,50});
poly_rect.add(Point{200,100});
poly_rect.add(Point{100,100});
win.attach(poly_rect);
poly_rect.add(Point{80,80});
win.set_label("Nyilszeruseg");
win.wait_for_button();

//Fill
r.set_fill_color(Color::blue);
poly.set_style(Line_style(Line_style::dash,9));
poly_rect.set_style(Line_style(Line_style::dash,6));
poly_rect.set_fill_color(Color::green);
win.set_label("Szines");
win.wait_for_button();

//Text
Text t{Point{150,250},"Hello, graph world!"};
win.attach(t);
win.set_label("Szoveg");
win.wait_for_button();

t.set_font(Font::courier);
t.set_font_size(30);
win.set_label("Szoveg nagyitas");
win.wait_for_button();

//Images
Image ii(Point{120,200}, "badge.jpg");
win.attach(ii);
win.set_label("Kep");
win.wait_for_button();

//More stuff
Circle c{Point{250,95}, 50};
Mark m{Point{250,105}, 'x'};
win.attach(c);
win.attach(m);
win.set_label("Kor");
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