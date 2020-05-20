#include <friend.h>
#include <iostream>
#include <friend.h>
using namespace std;

vfs::vfs() {
	numFs_=0;
}
int vfs::numFs() {
	return numFs_;
}
void vfs::numFs( int num ) {
	 numFs_ = num;
}
void vfs::showVfs(){

	cout<<"numFs "<<numFs_<<endl;

}

void setNumFs(vfs &v, int numFs){
	v.numFs_=numFs;
}
