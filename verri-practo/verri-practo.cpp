#include <iostream>
#include <singletone.h>
#include <friend.h>
#include <String.h>
#include <design_patterns.h>
using namespace std;

void singletone(){
	cout<<CONFIG::config()<<endl;
	cout<<CONFIG::config()<<endl;
}

void friend_test(){
	vfs v;
	v.showVfs();
	setNumFs(v, 100);
	v.showVfs();
}

void String_test(){
	String *str;
	str=new String("Somnath");
}


#include <fwk.h>

void Fwk_test() {
	Fwk *fwk=Fwk::fwk();
	int arr[]={1,2, 3,3, 3};
	int n=(sizeof(arr))/sizeof(*arr);
	fwk->printArray(arr, n);
	fwk->removeConsicativeArrayDuplicates(arr, n);
	fwk->printArray(arr, n);
	//fwk->printArray(arr, n);
	//cout<<fwk->reverseNumber(654321)<<endl;
}
#include <verri-practo.h>
int main( int argc, char *argv[] ) {
	RUN_TEST();
	return (0);
}
