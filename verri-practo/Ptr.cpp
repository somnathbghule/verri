#include <Ptr.h>

void Ptr_test () {
	shared::Ptr <int> p1(new int);
	shared::Ptr <int> p2=p1;
	shared:: Ptr <int> p3;
	p3=p2;
	cout<<"p3: " <<p3<<endl;
	cout<<"p2: "<<p2<<endl;
	cout<<"p1: "<<p1<<endl;


}
