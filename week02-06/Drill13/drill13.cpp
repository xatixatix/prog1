#include "Simple_window.h"
#include "Graph.h"

/*
g++ drill13.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o drill13 `fltk-config --ldflags --use-images`
*/

int main()
try{

using namespace Graph_lib;

//1
Simple_window win{Point{50,50}, 500, 500, "13. Drill"};
win.wait_for_button();

//2
int howManyX = 500;
int howManyY = 500;
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
win.wait_for_button();

//3
Vector_ref<Rectangle> vecR;

for (int i = 0; i < 8; ++i)
{
	vecR.push_back(new Rectangle(Point{}, gridSizeX, gridSizeY));
	
}

//4

for (int i = 0; i < 10; ++i)
{
	
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
