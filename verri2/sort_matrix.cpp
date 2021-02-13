// C++ implementation to sort the  
// major diagonal of the matrix 
  
#include <bits/stdc++.h> 
#include <iostream>
  
using namespace std; 
  
// Function to sort the major  
// diagonal of the matrix 
void sortDiagonal(int a[2][2], int M, int N) 
{ 
    // Loop to find the ith minimum 
    // element from the major diagonal 
    for (int i = 0; i < M; i++) { 
        int sm = a[i][i]; 
        int pos = i; 
          
        // Loop to find the minimum  
        // element from the unsorted matrix 
        for (int j = i + 1; j < N; j++) { 
            if (sm > a[j][j]) { 
                sm = a[j][j]; 
                pos = j; 
            } 
        } 
          
        // Swap to put the minimum 
        // element at the beginning of  
        // the major diagonal of matrix 
        swap(a[i][i], a[pos][pos]); 
    } 
  
    // Loop to print the matrix 
    for (int i = 0; i < M; i++) { 
        for (int j = 0; j < N; j++) 
            cout << a[i][j] << " "; 
        cout << endl; 
    } 
} 
  
// Driven Code 
int main() 
{ 
    int a[2][2] = { { 4, 3 }, 
                    { 2, 1 } }; 
  
    // Sort the major Diagonal 
    sortDiagonal(a, 2, 2); 
  
    return 0; 
} 
