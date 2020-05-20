#include <fwk.h>

Fwk *Fwk::fwk_=NULL;

void Fwk::removeArrayDuplicates(int *arr, int &n) {
	for (int i=0;i<n;i++) {
		for (int j=i+1;j<n;j++){
			if (arr[i]==arr[j]){
				while(j<n) {
					arr[j]=arr[j+1];	
					j++;
				}
				n--;
			}		
		}
	}
}

void Fwk::removeArrayDuplicates(int *arr, int &n, bool flag) {
	int index=0;
	for (int i=0;i<n;i++) {
		int j;
		for (j=0;j<i;j++)
			if (arr[i]==arr[j])
				break;
		if (i==j){
			arr[index++]=arr[i];	
		}
	}
	n=index;
}
		
void Fwk::removeConsicativeArrayDuplicates(int *arr, int &n) {
	int index=0;
	for ( int i=0; i<n; i++ ){
		if (arr[i]!=arr[i+1]){
			arr[index++]=arr[i];
		}
	}
	n=index;
}

int Fwk::reverseNumber(int n) {
	int revnum=0;
	while (n){
		int rem=n%10;
		n=n/10;
		revnum=(revnum *10)+rem;
	}
	return revnum;
}
void Fwk::printArray(int *arr, int &n) {
	for (int i=0;i<n;i++){
		cout<<arr[i]<<" ";			
	}	
	cout<<endl;
}
