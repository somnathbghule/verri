#ifndef queue_h
#define queue_h
#include <verri-practo.h>
namespace QUEUE {
	class queue {
		
		public:
			queue(int size=0) {
				size_=size;
				front_=-1;
				rear_=size_;
				buffer_=new int [size_];
				vals_=0;
			}				
			void push(int val);
			int pop();
			
			~queue() {
				delete buffer_;
			}
			
		private:
			int front_;
			int rear_;
			int size_;
			int *buffer_;
			int vals_;
	};
}
void queue_test ();

#endif
