#ifndef stats_h
#define stats_h

//
// Stats.
//
typedef enum PERTHREAD_STAT_ID {

#define STAT_DEF(name, comment) PTSTAT_ ## name,
#include "PerThreadStatDef.h"
#undef STAT_DEF
    PTSTAT_NumStat

} PERTHREAD_STAT_ID;


#endif
