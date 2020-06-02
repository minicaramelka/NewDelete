#include <iostream>
#include "alloc.h"

int main(){
	Overload* a = new Overload;
	delete a;

	Overload* b = new Overload[5];
	delete[] b;

	Overload* c = new(std::nothrow) Overload;
	delete c;

	Overload* d = new(std::nothrow) Overload[5];
	delete[] d;

	Allocator<int> alloc(10);
	int* e = alloc.allocate(11);
	alloc.deallocate(e, 6);

}