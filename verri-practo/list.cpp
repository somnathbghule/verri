#include <list.h>
list::list () {
	DEBUG();
	head_=NULL;
	tail_=NULL;
}
void list::printList() {
	List::node *curr=head_;
	while (curr){
		cout<<curr->data_<<" ";
		curr = curr->next_;
	}
	cout<<endl;
}
void list::reverseList() {
	DEBUG();
	List::node *curr=head_;
	List::node *next=NULL;
	List::node *prev=NULL;
	while ( curr ){
		next=curr->next_;
		curr->next_=prev;
		prev=curr;
		curr=next;
	}
	head_=prev;
}
List::node *list::getNthNodeFromLast (int n) {
	List::node *curr=head_;
	int i=0;
	while (i<n) {
		i++;	
		curr=curr->next_;
	}
	List::node *temp=head_;
	while ( curr ) {
		temp=temp->next_;
		curr=curr->next_;
	}
	return temp;
}

List::node * list::midOfList() {
	List::node *slow=head_;
	List::node *fast=head_;
	while ( slow && fast && fast->next_  ){
		slow=slow->next_;
		fast=fast->next_->next_;
	}
	return slow;
}

list::~list () { 
	DEBUG();
}
stack::stack() {
	DEBUG();
}
stack::~stack() {
	DEBUG();
}
void stack::insert ( int data ){
	if ( !head_ ){
		head_=new List::node(data);
		tail_=head_;
	} else {
		List::node *temp=new List::node(data);
		temp->next_=head_;
		head_=temp;
	} 
}
queue::queue() {
	DEBUG();
}
queue::~queue() {
	DEBUG();
}
void queue::insert ( int data ){
	if ( !head_ ){
		head_=new List::node(data);
		tail_=head_;
	} else {
		List::node *temp=new List::node(data);
		tail_->next_=temp;
		tail_=temp;
	} 
}
void list_test() {
	list *l=new queue();
	l->insert(10);
	l->insert(20);
	l->insert(30);
	l->insert(40);
	l->insert(50);
	l->printList();
	//l->reverseList();
	//l->printList();
	//cout<<"4: "<<l->getNthNodeFromLast(4)->data()<<endl;
	cout<<"mid: "<<l->midOfList()->data()<<endl;
	delete l;
}
