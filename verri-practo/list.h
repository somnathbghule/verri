#ifndef list_h
#define list_h
#include <verri-practo.h>
class list;
class Stack;
class queue;
namespace List {
	class node {
	
		public:
			node (int data=0) {
				data_=data;
				next_=NULL;
			}
			int data() {return data_;}
		private:
			int data_;
			node *next_;
			friend list;
			friend Stack;
			friend queue;
			//friend List::node *mergeSortedLists( List:: node *a, List::node *b);

	};

};
class list {
	public:
		list ();
		virtual ~list ();
		virtual void insert(int data)=0;
		void reverseList();
		void reverseListByNElements( List::node **head,int nElements );
		List::node * getNthNodeFromLast(int n);
		List::node * midOfList();
		void removeDuplicats();
		bool isPalindrome();
		bool isPalindromeV2();
		void printList();
		List::node *mergeSortedLists( List:: node *a, List::node *b);
		List::node *head_;
	private:
		//List::node *head_;
		List::node *tail_;
		friend Stack;
		friend queue;
};

class Stack: public list {
	public:
		Stack();
		void insert(int data);
		//const char *type() { return "Stack"; } does object slicing
		~Stack();

};
class queue: public list {
	public:
		queue();
		void insert(int data);
		//const char *type() { return "queue"; } does object slicing
		~queue();

};

void list_test();

#endif

