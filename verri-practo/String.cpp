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
void String::removeDuplicates() {
	bool alpha[ 256 ]={ false };
	int index=0;
	int i=0;
	for ( i=0; i< size_; i++ ){
		if ( alpha[ buffer_[i] ] == false ) {
			alpha[ buffer_[i] ] = true;
			buffer_[ index++ ]=buffer_[ i ];
		}
	}
	size_ = index;
	buffer_[ index ] = '\0';
}
