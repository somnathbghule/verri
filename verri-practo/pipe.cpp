
#include <verri-practo.h>
void parentWriteChildRead () {
	int fd[2];
	int ret=pipe(fd);
	if ( ret ){
		cout <<"pipe failed"<<endl;
	}
	int pid=fork();
	if ( pid < 0  )
		cout <<"fork failed"<<endl;
	if ( pid > 0 ) {
			cout<<"I am parent: "<<getpid()<<endl;
			char buffer[4];
			read( fd[0], buffer, 4);
			cout<<"buffer: "<<buffer <<endl;

	} else if ( pid==0 ){
			cout<<"I am child: "<<getpid()<<endl;
			write( fd[1], "Msys", 4 );
		
	}

}
void test_Pipe() {
	parentWriteChildRead();
}
