#ifndef Ptr_h
#define Ptr_h
#include <verri-practo.h>
namespace shared {
	template < typename T >
	class Ptr {

	public:		
		Ptr ( T *ptr=NULL ):refCount_(0), ptr_(ptr) {
			DEBUG();
			if ( ptr ){
				refCount_++;
				ptr_=ptr;
			} 
		}
		Ptr ( Ptr &ptr ){
			DEBUG();
			refCount_++;
			ptr.refCount_++;
			ptr_=ptr.ptr_;
				
		}
		Ptr &operator=(Ptr &ptr) {
			DEBUG();
			refCount_++;
			ptr.refCount_++;
			ptr_=ptr.ptr_;
			return *this;
				
		}
		T &operator *() {return *ptr_;}
		T *operator ->() {return ptr_;}
		~Ptr() {
			refCount_--;
			if (!refCount_){
				DEBUG();
				delete ptr_;
			}
		}
		T *ptr() {return ptr_;}
		T refCount() {return refCount_;}
		friend ostream & operator << (ostream &out, shared::Ptr <T> &ptr ) {
			out << "ptr: "<< ptr.ptr() <<" refCount: "<<ptr.refCount()<<endl;
			return out;
		}
		private:
			T *ptr_;
			T refCount_;
	};
};
void Ptr_test();
#endif
