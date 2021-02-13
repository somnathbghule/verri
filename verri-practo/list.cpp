#include <list.h>
list::list () {
	DEBUG();
	head_=NULL;
	tail_=NULL;
}
void list::printList() {
	List::node *curr=head_;
	while (curr){
		cout<<curr<<" "<<curr->data_<<" "<<endl;
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
void list::reverseListByNElements( List::node **head, int nElements ) {
	DEBUG();
	List::node *curr=*head;
	List::node *next=NULL;
	List::node *prev=NULL;
	List::node *headTemp=*head;
	int i=0;
	while ( curr && i < nElements ){
		next=curr->next_;
		curr->next_=prev;
		prev=curr;
		curr=next;
		i++;
	}
	*head=prev;

	if ( curr ){
		reverseListByNElements( &curr, nElements );
		headTemp->next_=curr;
	}
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
	while ( slow && fast && fast->next_ && fast->next_  ){
		slow=slow->next_;
		fast=fast->next_->next_;
	}
	return slow;
}

#include <stack>
bool list::isPalindrome() {
	cout <<__func__<<endl;
	stack <List::node*> firstHalf;
	List::node *slowPtr = head_;
	List::node *fastPtr = head_;
	int count = 1;
	while ( slowPtr && fastPtr && fastPtr->next_ ) {
		fastPtr = fastPtr->next_->next_;
		if ( fastPtr ) {
			count+=2;
		} else {
			count+=1;
		}
		firstHalf.push( slowPtr );
		slowPtr = slowPtr->next_;
	}
	List::node *mid = firstHalf.top();
	cout <<" mid: " << mid->data()<<" size: "<< firstHalf.size() <<endl;
	cout <<" count: " << count <<endl;
	
	if ( count%2 )
		slowPtr=slowPtr->next_;

	while ( slowPtr ) {
		if ( slowPtr->data() != firstHalf.top()->data() )
			return false;
		firstHalf.pop();
		slowPtr=slowPtr->next_;
	}
	return true;
}

bool list::isPalindromeV2() {
	stack <List::node*> firstHalf;
	List::node *slowPtr = head_;
	List::node *fastPtr = head_;
	List::node  *prev=NULL;
	while ( fastPtr && fastPtr->next_ ) {
		firstHalf.push( slowPtr );
		slowPtr = slowPtr->next_;
		fastPtr = fastPtr->next_->next_;
	}
	if ( fastPtr ) { //odd elements_
		slowPtr = slowPtr->next_;
	}
	while ( slowPtr  ) {
		if ( slowPtr->data() != firstHalf.top()->data() )
			return false;
		firstHalf.pop();
		slowPtr = slowPtr->next_;
	}
	return true;
}

void list::removeDuplicats() {
	List::node *curr = head_;
	while ( curr ) {
		if ( curr->next_ && curr->data() == (curr->next_)->data() ) {
			List::node *n=curr->next_;
			curr->next_ = curr->next_->next_;
			delete n;
			n=NULL;
		}  	
		curr=curr->next_;
	}
}
List::node *list::mergeSortedLists( List::node *a, List::node *b) {
	if ( a==NULL )
		return b;
	if ( b==NULL )
		return a;
	List::node *result=NULL;
	if ( a->data() < b->data() ){
		result=a;
		result->next_=mergeSortedLists(a->next_, b);
	} else {
		result=b;
		result->next_=mergeSortedLists(a, b->next_);
	}
	return result;
}

list::~list () { 
	DEBUG();
}
Stack::Stack() {
	DEBUG();
}
Stack::~Stack() {
	DEBUG();
}
void Stack::insert ( int data ){
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
	//list *l=new queue();
	//l->insert(10);
	//l->insert(20);
	//l->insert(50);
	//l->printList();
	//list *l2=new queue();
	//l2->insert(30);
	//l2->insert(40);
	//l2->insert(60);
	//l2->printList();
	//List::node* res=l->mergeSortedLists( l->head_, l2->head_ );
	list *l3=new queue();
	l3->insert( 1 );
	l3->insert( 2 );
	l3->insert( 3 );
	l3->printList();
	cout<<"isPalindromeV2: "<<l3->isPalindromeV2()<<endl;

}
