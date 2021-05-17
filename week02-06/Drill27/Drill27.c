#include<stdio.h>
#include <stdlib.h>

void f(const char* p, const int x){

	printf("%s\t%i\n", p,x);
}


int main() {
    
    
	printf("Classic hello world: \n");
    printf("Hello World\n");
    printf("\n");


    
    printf("Hello World with two variables: \n");
    const char* hello = "Hello";
    const char* world = "World";


    printf("%s %s\n", hello, world);
    printf("\n");

    f("foo", 7);
    f("yes", 43252);
    f("no", -54);


    return 0;
}