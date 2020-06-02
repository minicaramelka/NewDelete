#pragma once
#include <stdexcept>
#include "operators.h"
using namespace std;

template <class T>
class Allocator{

public:
	Allocator(size_t size) :_size(size) {};

	void destroy(T* tmp) const {
		tmp->~T();
	}

	T* allocate(size_t size){
		if (size > _size)
			throw bad_alloc();
		else
			return new T[size];
	}

	void deallocate(T* ptr, size_t size){
		delete[] ptr;
	}

	T* max_size() {
		return sizeof(T);
	}

private:
	size_t _size;
};