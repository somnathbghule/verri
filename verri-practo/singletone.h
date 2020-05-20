#ifndef singletone_h
#define singletone_h
#include <String.h>

class CONFIG {
	public:
		static CONFIG * config();
	private:
		CONFIG();
		CONFIG( const CONFIG &config );
		CONFIG &operator=( const CONFIG &config );
		static CONFIG *config_;
};

#endif
