#include <iostream>
#include "alloc.h" 
#include "operators.h"

using namespace std;

void* Overload::operator new(size_t size){
	void* allocMem = malloc(size);
	if (allocMem == 0){
		throw bad_alloc();
	}
	else
		return allocMem;
}

void Overload::operator delete(void* tmp){
	free(tmp);
}

void* Overload::operator new[](size_t size){
	void* allocMem = malloc(size);
	if (allocMem == 0){
		throw bad_alloc();
	}
	else
		return allocMem;
}

void Overload::operator delete[](void* tmp){
	free(tmp);
}

void* Overload::operator new(size_t size, const std::nothrow_t&){
	return malloc(size);
}

void* Overload::operator new[](size_t size, const std::nothrow_t&){
	return malloc(size);
}