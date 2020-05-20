#ifndef fwk_h
#define fwk_h
#include <iostream>
using namespace std;

class Fwk {
	public:
		static Fwk *fwk() {
			if (!fwk_) {
				fwk_=new Fwk();
			}
			return fwk_;
		}
		static void removeArrayDuplicates(int *arr, int &n);
		static void removeArrayDuplicates(int *arr, int &n, bool flag);
		void removeConsicativeArrayDuplicates(int *arr, int &n);
		static void printArray(int *arr, int &n);
		int reverseNumber(int n);
	private:
		Fwk(){}
		static Fwk *fwk_;
};

#endif
