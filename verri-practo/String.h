#ifndef String_h
#define String_h
#include <iostream>
#include <string.h>
using namespace std;

#define DEBUG() (cout<<__func__<<" "<<this<<endl)
#define DEBUG_V1() (cout<<__func__<<endl)


class String {
	public:
		String(const char *str=NULL);
		String(const String &str);
		~String();
		friend ostream& operator << (ostream &out, const String &str);
		String &operator=(const String &str);
		char &operator[](int index);
		char *Str() const;
	private:
		int size_;
		char *buffer_;
		mutable int strCount;

};

#endif 
