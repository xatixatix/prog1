#include "Simple_window.h"
#include "Graph.h"

/*
g++ drill13.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o drill13 `fltk-config --ldflags --use-images`
*/

int main()
try{

using namespace Graph_lib;

//1
Simple_window win{Point{50,50}, 500, 400, "13. Drill"};

//2
int howManyX = 400;
int howManyY = 400;
int gridSizeX = 50;
int gridSizeY = 50;

Lines grid;
for(int x = gridSizeX; x <= howManyX; x += gridSizeX){
    grid.add(Point{x,0}, Point{x,howManyY});
}
for(int y = gridSizeY; y <= howManyY; y += gridSizeY){
    grid.add(Point{0,y}, Point{howManyX,y});
}

win.attach(grid);
win.set_label("Grid");	
win.wait_for_button();

//3
Vector_ref <Rectangle> rr;
win.set_label("Red Rectangles");
for(int i=0;i<8;i++){
	rr.push_back(new Rectangle(Point(i*gridSizeX,i*gridSizeY),gridSizeX,gridSizeY));
	rr[i].set_fill_color(Color::red);
	win.attach(rr[i]);	
}
win.wait_for_button();

//4
win.set_label("Little Cats");

Image littleCatImage{Point{100,0}, "littlecats.jpeg"};
littleCatImage.set_mask(Point{100,0},100,100);

Image littleCatImage2{Point{250,0}, "littlecats.jpeg"};
littleCatImage2.set_mask(Point{100,0},100,100);

Image littleCatImage3{Point{250,150}, "littlecats.jpeg"};
littleCatImage3.set_mask(Point{100,0},100,100);

Image littleCatImage4{Point{50,250}, "littlecats.jpeg"};
littleCatImage4.set_mask(Point{100,0},100,100);

win.attach(littleCatImage);
win.attach(littleCatImage2);
win.attach(littleCatImage3);
win.attach(littleCatImage4);

win.wait_for_button();

//5
Image movingCatImage{Point{0,0}, "movingCat.gif"};
movingCatImage.set_mask(Point{25,25},50,50);

win.attach(movingCatImage);
win.wait_for_button();

for (int i = 0; i < 8; ++i)
{
	for (int j = 0; j < 8; ++j)
	{
		win.wait_for_button();
		if (j<7)
		{
			movingCatImage.move(50,0);
		}
		else{
			movingCatImage.move(-350,50);
		}
	}
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
