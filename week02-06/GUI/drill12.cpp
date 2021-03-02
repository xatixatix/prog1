#include "Simple_window.h"
#include "Graph.h"


int main()
try{

using namespace Graph_lib;


Point tl{150,100};

Simple_window win{tl, 600, 400, "My_window"};
win.wait_for_button();

Polygon poly;

poly.add(Point{310,200});
poly.add(Point{420,100});
poly.add(Point{420,200});
win.set_label("derekszog");


win.attach(poly);

win.wait_for_button();


//Axis

Axis xa{Axis::x, Point(20,350), 330, 12, "x.axis"}; //axis::x means horizontal

 win.attach(xa);
 win.set_label("x_axis");
 win.wait_for_button();

 Axis ya{Axis::y, Point(20,350), 330, 12, "y.axis"}; //axis is vertical
 ya.set_color(Color::yellow);
 ya.label.set_color(Color::blue);
 win.attach(ya);
 win.set_label("y_axis");
 win.wait_for_button();


//Function

Function sine(sin,0,100,Point{20,150}, 1000,30,30);
win.attach(sine);
win.set_label("sinus");
win.wait_for_button();
sine.set_color(Color::red);


//Polygons

Polygon poly2;
poly2.add(Point{300,300});
poly2.add(Point{350,100});
poly2.add(Point{400,300});
poly2.set_color(Color::blue);
poly2.set_style(Line_style::dash);
win.attach(poly2);
win.set_label("big_triangle");
win.wait_for_button();

//Rectangle

Rectangle r{Point{200,200}, 100,50};
win.attach(r);
win.set_label("rect");
win.wait_for_button();


Closed_polyline poly_rect;
poly_rect.add(Point{100,50});
poly_rect.add(Point{200,50});
poly_rect.add(Point{200,100});
poly_rect.add(Point{100,100});
win.attach(poly_rect);
poly_rect.add(Point{50,75});
win.set_label("yes");
win.wait_for_button();


//Fill

r.set_fill_color(Color::blue);
poly.set_style(Line_style(Line_style::dash,9));
poly_rect.set_style(Line_style(Line_style::dash,6));
poly_rect.set_fill_color(Color::green);
win.set_label("nice_colors");
win.wait_for_button();

//Text

Text t{Point{150,150},"Hello, graph world!"};
win.attach(t);
win.set_label("text");
win.wait_for_button();

t.set_font(Font::courier);
t.set_font_size(23);
win.set_label("bigger_text");
win.wait_for_button();

//Images
Image ii(Point{20,30}, "badge.jpg");
win.attach(ii);
win.set_label("image");
ii.move(100,200);
win.wait_for_button();

//More stuff
Circle c{Point{250,95}, 50};
Mark m{Point{250,100}, 'x'};

win.attach(c);
win.attach(m);
win.set_label("circle");
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