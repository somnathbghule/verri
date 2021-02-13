#include <iostream>
#include <string>
#include <stack>
#include <map>
using namespace std;

string initialsOfName ( string text ) {
	string init;
	bool isInit = false; 
	for ( char c:text ) {
		if ( isalpha( c ) && isInit == false ) {
			init.push_back( c );
			isInit = true;	
		} else if ( isspace( c ) && isInit  ) {
			isInit = false;
			init.push_back ( c );
		}
	}
	cout << "intials: "<<init<<endl;
	return init;
}

bool isInteger ( string text  ) {
	
	for ( char c : text ) {
		if ( isdigit( c ) == false )	
			return false;
	}

	//return 
	return true;
}

void removingPunctuations( string text ) {
	int index=0;
	int len=text.length();
	cout << "text: "<<text<<endl;
	for ( int i=0;i<len; ++i )  {
		if ( isalpha( text[i] ) || isspace( text[ i ]) ) {
			text [ index ]	= text[ i ];
			++index;
		}
	}
	text.erase(index);
	cout << "text: "<<text<<endl;
}

#define RESULT( res ) ( res?"Balanced":"Not Balanced" )

enum Para {
	col,
	curl,
	square
};

string isBalancedV1( string text ) { 
	map <Para, int> paraCount;
	int len = text.length();
	for ( int i=0; i<len; i++ ) {
		if ( text[ i ] == '(' )
			paraCount[ col ]++;			
		else  if ( text[ i ] == '{' )
			paraCount[ curl ]++;			
		else  if ( text[ i ] == '[' )
			paraCount[ square ]++;			
		else  if ( text[ i ] == ')' )
			paraCount[ col ]--;			
		else  if ( text[ i ] == '}' )
			paraCount[ curl ]--;			
		else  if ( text[ i ] == ']' )
			paraCount[ square ]--;			
	}
	return RESULT( paraCount[col]==0 && paraCount[ curl ] ==0 && paraCount[ square ] == 0 );
}
string isBalanced( string text ) {
	stack <char> s;
	int len = text.length();
	int i = 0;
	while ( i < len ) {
		if ( text[i] == '(' || text[i] == '[' || text[i] == '{' ) {
			s.push( text[i] );
			++i;
		} else if ( !s.empty() ) {
			char c = s.top();
			s.pop();
			switch ( text[ i ] ) {
				case ')':
					{
						if ( c == '{' || c == '[' )
							return RESULT( false );
					}
					break;
				case ']':
					{
						if ( c == '{' || c == '(' )
							return RESULT( false );
					}
					break;
				case '}':
					{
						if ( c == '(' || c == '[' )
							return RESULT( false ) ;
					}
					break;
				}
				++i;
			} else 
				return RESULT( false );

		} 
		return RESULT( s.empty() );
}

void removeExtraSpaces( string text ) {
	int index =0;
	int len = text.length();
	cout <<"before: "<<"\""<<text<<"\""<<endl;
	bool isWord = false;
	for ( int i=0;i<len;++i) {
		//logic to skip extra spaces
		if( isWord && isspace ( text[ i ]  ) && !  isspace ( text[ i+1 ] ) && ( text [ i+1 ] != '.' ) && ( i != len - 1) ) {  
			text[ index ] = text[ i ];						
			++index;
			isWord=false; 
		} else if ( isspace ( text[ i ]  ) == false ) {
			text[ index ] = text[ i ];
			++index;
			isWord = true;
		} 
	}
	text.erase( index );
	cout <<"after: "<<"\""<<text<<"\""<<endl;
}

void SWAP_CHAR (char &c1 , char &c2 ) {
	char temp;
	temp=c1;
	c1=c2;
	c2=temp;
}
void reverseWord( string &text, int begin, int end ) {
	for ( int k=0,j=begin; k<(end - begin)/2; ++k,++j ) {
		SWAP_CHAR( text[ j ], text[ end - k - 1 ] );
	}
}
void reverseWordFromStatement( string text ) {
	int len=text.length();
	cout <<"input: "<<text <<endl;	
	for ( int i=0;i<len/2;++i )	
		SWAP_CHAR( text[ i ], text[ len-i-1 ] );


	//reverse just word
	int index=0;
	for ( int i=0;i<len;++i ) {	
		if ( isspace ( text[ i  ] ) ) {
			reverseWord( text, index, i );
			index=i+1;
		}
	}
	cout <<"output: "<<text <<endl;	
}

void isWordsPresent( string text, string smallTexts[ 5 ] ) {
	bool isPresent[5]={false};

	for ( int i=0; i<5; i++ ) {
		if ( text.find( smallTexts[i] ) != string::npos )		
			isPresent[ i ] = true;
	}
	for (bool b:isPresent )
		cout <<b <<endl	;
}
#include  <bits/stdc++.h> 
char maximumOccuringCharacter( string text ) {
	map<char, int> cMap;
	int len=text.length();
	for ( int i=0;i<len;i++) {
		if ( isspace( text[ i ] ) == false )
			cMap[ text[ i ] ]++;
	}
	int max = INT_MIN;
	char c=0;
	for ( int i=0;i<len;i++) {
		if ( cMap[ text[ i ] ] > max ) {
			max = cMap[ text[ i ] ];
			c = text[ i ];
		}
	}
	return c;
}
char maximumOccuringCharacterV2( string text ) {
	char charCount[ 255 ] = { 0 };
	int len=text.length();
	for ( int i=0;i<len;i++) {
		if ( isspace( text[ i ] ) == false )
			charCount[ (int)text[ i ] ]++;
	}
	int max = INT_MIN;
	char c=0;
	for ( int i=0;i<len;i++) {
		if ( charCount[  (int)text[i] ] > max ) {
			max = charCount[ (int )text[i] ];
			c = text[ i ];
		}
	}
	return c;
}

void putSpacesAfterCapital ( string text ) {
	int len = text.length();
	string result;
	int i=0;
	cout<<"intput: "<<text<<endl;
	result.push_back( tolower( text[ i ] ));
	for (  i=1;i<len; i++) {
		if ( isupper( text[ i ] ) ) {
			result.push_back( ' ' );
			result.push_back( tolower( text[ i ] ));
		} else {
			result.push_back(  text[ i ] );
		}
			
	}
	text.clear();
	text.append(result);
	cout<<"output: "<<text<<endl;

}


int main ( int argc, char **argv ) {
	//string text = "([])({{[[]]}}())()";
	//cout <<"isBalanced: " << isBalanced (text)<<endl;
	//string text = "!!!how is :../&*'the man!!!";
	//removingPunctuations( text );
	
	//string text = "Somnath Ghule" ;
	//initialsOfName ( text );
	//
	//string text = " 12             SOMN                  ATH                3B ";
	//string text = "   Hello Geeks . Welcome   to  GeeksforGeeks   .    ";
	//string text = "GeeksforGeeks";
	//cout<<"isInteger: " <<isInteger( text )<<endl;
	///removeExtraSpaces ( text );
	//string text="I am Indian";
	//string text="I love pune";
	//reverseWordFromStatement( text );
	//string text="I am in Pune Maharashtra";
	//string smallTexts[] = {"I", "In", "Mumbai", "India", "No"};
	//isWordsPresent( text, smallTexts );
	//string text="sample program";
	//cout<<"maximumOccuringCharacter: "<<maximumOccuringCharacter( text )<<endl;
	//cout<<"maximumOccuringCharacterV2: "<<maximumOccuringCharacterV2( text )<<endl;
	string text="IAmInPune";
	putSpacesAfterCapital(text);
	//return from main
	return (0);
}

