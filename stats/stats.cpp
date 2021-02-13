#include <iostream>
#include "stats.h"
using namespace std;

/* Return the index of a stat given its name. */
#define PTSTATINDEX( name )  PTSTAT_##name

// Define per thread stats
struct PerThreadStats {
        int statCountersTable[PTSTAT_NumStat];
	public:
	    PerThreadStats () {
		#define STAT_DEF ( name, comment ) \
		    statCountersTable [ PTSTATINDEX( name ) ] = 0;
			#include "PerThreadStatDef.h"
		#undef STAT_DEF
	    }
	    int getVal ( PERTHREAD_STAT_ID  index ) {
	   	return statCountersTable [ index ]; 
	    }
	    void setVal ( PERTHREAD_STAT_ID  index, int val ) {
	   	statCountersTable [ index ] = val; 
	    }
	    void inc( PERTHREAD_STAT_ID  index ) {
	   	++statCountersTable [ index ]; 
	    }
	    void dec( PERTHREAD_STAT_ID  index ) {
	   	--statCountersTable [ index ]; 
	    }
	    ~PerThreadStats() {
	    
	    }

};

PerThreadStats stats;
#define STAT_GET( name ) ( stats.getVal( PTSTATINDEX( name )))
#define STAT_SET( name, val ) ( stats.setVal( PTSTATINDEX( name ), val ))
#define STAT_INC( name ) ( stats.inc( PTSTATINDEX( name )) )
#define STAT_DEC( name ) ( stats.dec( PTSTATINDEX( name )) )

int main(int argc, char *argv[]){
	cout << "STAT_GET: "	<<STAT_GET( NumTransactions )<<endl;
	STAT_SET( NumTransactions, 100 );
	cout << "STAT_GET: "	<<STAT_GET( NumTransactions )<<endl;
	STAT_INC( NumTransactions );
	cout << "STAT_GET: "	<<STAT_GET( NumTransactions )<<endl;
	STAT_DEC( NumTransactions );
	cout << "STAT_GET: "	<<STAT_GET( NumTransactions )<<endl;
	//return from main
	return (0);
}
