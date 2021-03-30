/*
    g++ drill16.cpp Graph.cpp Window.cpp GUI.cpp Lines_window.cpp -o drill16 `fltk-config --ldflags --use-images`
*/
#include "Lines_window.h"
#include "Graph.h"

int main()
try{
    Lines_window win {Point{100,100}, 1000, 500, "Drill 16"};
    
    return gui_main();
}
catch(exception& e){
	cerr << "Exception: " << e.what() << '\n';
	return 1;
}
catch(...){
	cerr << "Some exception:\n";
	return 2;
}