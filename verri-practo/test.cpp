#include <iostream>
using namespace std;

void search( int *arr, int n, int val ) {
	int l=0;  
	int h=n-1;
	int m=0;
	while ( l <= h ) {
		
		m= (l+h)/2;

		if ( arr[m]==val){		
			cout<<"found"<<endl;
			return;
		}
		if ( val < arr[m] )
			h=m-1;
		else
			l=m+1;
				
	}
	cout<<"not found" <<endl;	
	return;
}

// C++ program to search an element in row-wise
// and column-wise sorted matrix
#include<bits/stdc++.h>
using namespace std;
#define MAX 100

/* Searches the element x in mat[m][n]. If the
   element is found, then prints its position
   and returns true, otherwise prints "not found"
   and returns false */
bool search(int mat[][MAX], int m, int n, int x)
{
   int i = m-1, j = 0;  //set indexes for bottom left element
   while ( i >= 0 && j < n )
   {
      if ( mat[i][j] == x )
         return true;
      if ( mat[i][j] > x )
        i--;
      else //  if mat[i][j] < x
        j++;
   }

   return false;
}

// driver program to test above function
int main()
{
  int mat[][MAX] = { {10, 20, 30, 40},
                     {15, 25, 35, 45},
                     {27, 29, 37, 48},
                     {32, 33, 39, 50},
                     {50, 60, 70, 80},
                  };
  if (search(mat, 5, 4, 70))
      cout << "Yes";
  else
      cout << "No";
  return 0;
}
/*
int main(int arc, char **argv ){
	
	int arr[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };

	int *arr_ref=(int *)arr;
	int n=(sizeof(arr))/sizeof(**arr);
	search( arr_ref, n, );
	return 0;
}*/
