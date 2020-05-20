#include <queue.h>
void QUEUE::queue::push(int val) {
	if ( vals_ >= size_ ){
		cout<<"queue full !!!"<<endl;
	}
	front_=(front_+1)%size_;
	buffer_[front_]=val;
	vals_++;
}
int QUEUE::queue::pop() {
	if ( vals_ <= 0 ){
		cout<<"queue empty !!!"<<endl;
	}
	rear_=(rear_-1)%size_;
	int val=buffer_[rear_];
	vals_--;
	return val;
}

void queue_test (){
	QUEUE::queue q(2);
	q.push(1);
	q.push(2);
	q.pop();
	q.push(3);
}

