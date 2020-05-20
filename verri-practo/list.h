#ifndef list_h
#define list_h
#include <verri-practo.h>
class list;
class stack;
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
			friend stack;
			friend queue;
	};

};
class list {
	public:
		list ();
		virtual ~list ();
		virtual void insert(int data)=0;
		void reverseList();
		List::node * getNthNodeFromLast(int n);
		List::node * midOfList();
		void printList();
	private:
		List::node *head_;
		List::node *tail_;
		friend stack;
		friend queue;
};

class stack: public list {
	public:
		stack();
		void insert(int data);
		//const char *type() { return "stack"; } does object slicing
		~stack();

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

