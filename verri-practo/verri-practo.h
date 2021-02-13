#ifndef verri_practo_h
#define verri_practo_h
#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
#include <pthread.h>
using namespace std;
#define DEBUG() (cout<<__func__<<" "<<this<<endl)
#define DEBUG_V1() (cout<<__func__<<endl)
#include <tree.h>
#include <list.h>
#include <queue.h>
#include <Ptr.h>
#include <number.h>
#include <even_odd.h>
#include <pipe.h>
#include <series.h>
#define RUN_TEST() (test_series())
#endif
