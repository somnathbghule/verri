#ifndef design_patterns_h
#define design_patterns_h

#include <iostream>
#include <String.h>
using namespace std;

template <typename T>

class Ptr {
	public:
		Ptr(T *ptr=NULL) {
			DEBUG();
			ptr_=ptr;
		}
		T *operator->() {
			return ptr_;
		}
		T &operator*() {
			return *ptr_;
		} 
		~Ptr() {
			DEBUG();
			delete ptr_;
		}
	private:
		T *ptr_;
};

#endif
