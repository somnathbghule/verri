#include <verri-practo.h> 

pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;

int n=0;

void * even ( void *param ) {
	sleep(1);
	pthread_mutex_lock(&mutex);
	while ( n < TOTAL_NUMBERS ) {
		if ( n%2==0 ) {
			cout <<__func__<<" "<<n++<<endl;
		} else 
			pthread_mutex_unlock( &mutex);
	}	
	return NULL;
}

void * odd ( void *param ) {
	pthread_mutex_lock(&mutex);
	while ( n < TOTAL_NUMBERS ) {
		if ( n%2 ) {
			cout <<__func__<<" "<<n++<<endl;
		} else 
			pthread_mutex_unlock( &mutex);
	}
	return NULL;

}

void even_odd_test () {

	/*
	pthread_t  tid [2];
	 int ret=pthread_create (&tid[0], NULL, odd, NULL);
	 if ( ret )
		 cout << "odd thread creation failed"<<endl;
	 ret=pthread_create (&tid[1], NULL, even, NULL);
	 if ( ret )
		 cout << "even thread creation failed"<<endl;

	 pthread_join(tid[0], NULL);
	 pthread_join(tid[1], NULL);
	 */

	int *in=new int[100];
	//free( in );
	//free( in );
/*
	void *ptr= (void *)in;
	cout <<ptr<<endl;
	++(static_cast<int *>ptr);
	cout <<ptr<<endl;
	*/
} 
