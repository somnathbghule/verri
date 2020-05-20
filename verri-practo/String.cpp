#include <String.h>
String::String(const char *str) {
	DEBUG();
	if ( str ){
		size_=strlen(str);
		buffer_=new char[size_];
		strcpy(buffer_, str);
	} else {
		size_=0;
		buffer_=NULL;
	}
	strCount=0;
}
String::~String(){
	DEBUG();
	if ( buffer_ )
		delete buffer_;
}
String &String::operator=(const String &str){
	DEBUG();
	delete buffer_;
	size_=strlen(str.buffer_);
	buffer_=new char [size_];
	strcpy(buffer_, str.buffer_);
}
char &String::operator[](int index) {
	DEBUG();
	if( index>=0 && index<=size_ ){
		return buffer_[index];
	}
}
String::String(const String &str) {
	DEBUG();
	size_=strlen(str.buffer_);
	buffer_=new char [size_];
	strcpy(buffer_, str.buffer_);
}
ostream &operator <<(ostream &out, const String &str) {
	DEBUG_V1();
	if (str.buffer_)
		out <<"size: "<< str.size_ <<" buffer: "<<str.buffer_<<"\n"<<endl;
	return out;
}

char *String::Str() const {
	strCount++;	
	return buffer_;
}
