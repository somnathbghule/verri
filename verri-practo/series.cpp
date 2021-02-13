#include <series.h>
#include <String.h>
void fibona( int n ){
	int sum=1;
	int prev=0;
	int t=0;
	while ( n-- ){
		cout<<sum<<" ";
		t=sum;
		sum=prev+sum;
		prev=t;
	}
}

bool isDuck( int num ) {
	bool isDuckFlag = false;
  	int rem = 0;
  	while ( num ) {
	cout <<"rem: "<<num%10<<endl;
    	if ( num % 10 == 0 )	{
        	isDuckFlag = true;
        } else if ( isDuckFlag == true ) {
        	return true;
        }
      	num=num/10;
    }
    return false;
}

#include <bits/stdc++.h>

string reverse ( string str ) {
	int len = str.length();
  	int index = 0;
	cout <<str<<endl;	
	cout <<len<<endl;
  	for ( int i=0; i<len/2; i++ ) {
		cout <<len - i - 1<<endl;
		swap( str[ i ] , str[ len-i-1] );
	 }
	cout <<str<<endl;	
  	for ( int i=0; i< len; i++ ) {
    		if ( str[ i + 1   ] == ' ' || str [ i + 1 ] == '\0' ) {
        		for ( int j=index;j<i;j++ ) {
              			swap(str[ j  ],  str[ i - j - 1 ]);
            		}
          		index = i+1;
           	}
    	}
  	return str;
}

#include <map>

enum ParaType {
	none=-1,
	first,
	MAX=100
};
/*
bool isBalancedParenthesis( string text ) {
	int tLen = text.length();
	int roundBracketCount=0;
	
	map < int , int > paraMap;
	for ( int i=0;i<tLen; i++ ) {
		if ( text[i] == '(' )  
			++paraMap[ round ];
		else if ( text[i] == '{' )  
			++paraMap[ curl ];
		else if ( text[i] == '[' )  
			++paraMap[ square ];
		else if ( text[i] == ')' )  
			--paraMap[ round ];
		else if ( text[i] == '}' )  
			--paraMap[ curl ];
		else if ( text[i] == ']' )  
			--paraMap[ square ];
	}
	return ( paraMap.at(round) == paraMap.at(curl) == paraMap.at(square) == 0 );
}
*/
void test_series() {
	//cout<<"isDuck: "<<isDuck( 0010 )<<endl;
	//string str="I am programmer";
	//cout << reverse (str)<<endl;
	//string text = "{(a+b)(b+1)}";
	//cout <<"isBalancedParenthesis: "<< isBalancedParenthesis ( text )<<endl;
	cout<<none<<endl;
	cout<<first<<endl;
	cout<<MAX<<endl;
}
