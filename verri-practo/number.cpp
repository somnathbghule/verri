#include <verri-practo.h>

int factorial( int n ) {
	int fact=1;
	if ( n==0 )
		return 0;

	for (int i=2;i<=n; i++ ){
		fact=fact*i;
	}
	return fact;
}

int multiply( int x, int res[], int res_size ) {
	int carry=0;

	for (int i=0; i<res_size;i++ ) {
		int product=res[i]*x+carry;
		res[i]=product%10;
		carry=product/10;
	}

	while ( carry ) {
		res[ res_size ] = carry%10;
		carry = carry/10;
		res_size++;
	}

	return res_size;

}

void huge_factorial( int n ) {

	int res[1024];
	res[0]=1;
	int res_size=1;
	for ( int x=2;x<=n;x++ ) {
		res_size=multiply(x, res, res_size);
	}

	cout<<"fact of " <<n <<" ";
	for (int i=res_size-1;i>=0;i-- ) {
		cout <<res[i];
	}
	cout <<endl;
}

bool isPower2( int num ) {
	return num && !(num & (num -1));
}

int addUsingBitwise( int x, int y ) {
	int carry = 0;
	while ( y ) {
		carry=x&y;
		x=x^y;
		y=carry<<1;
	}
	return x;
}
void number_test() {

	//cout<< "fact 5: "<< factorial( 100 )<<endl; 
	//huge_factorial( 100 ); 
	
	//cout <<"isPow2: 32 " << isPower2(32) <<endl;
	//cout <<"isPow2: 31 " << isPower2(31) <<endl;
	cout <<"addUsingBitwise(10, 20): " << addUsingBitwise (10, 20)<<endl;
}
