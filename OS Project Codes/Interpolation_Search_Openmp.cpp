#include<stdio.h>
#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<omp.h>
using namespace std;

void interpolationSearch(int arr[], int n, int key) {

	int Low = 0, High = n-1;
	bool flag = true;
	
	#pragma omp prallel
	{
		while(Low <= High && key >= arr[Low] && key <= arr[High]) {

			if(Low == High) {
				cout<<"Element found at position "<<Low<<endl;
			}
			int q = (key - arr[Low])/(arr[High] - arr[Low]);
			int pos = Low + (High - Low) * q;
			if(arr[pos] == key) {
				cout<<"Element found at position "<<pos<<endl;
				flag = false;
			}
			if(arr[pos] < key) {
				Low = pos + 1;
			} else {
				High = pos - 1;
			}
		}
	}
	if(flag == true) {
		cout<<"Element not found"<<endl;
	}
}

//Main function to take in the inputs from the user
int main() {
	int n=10000,i,x;
	int arr[n];
	for(int i=0; i<n; i++) {
		arr[i] = rand()%10000;
	}

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
		}

	}

	for(int i=0; i<n; i++) {
		cout<<arr[i]<<" ";
	}

	cout<<"\nEnter the element to be searched\n";
	cin>>x;

	float t1 = clock();
	interpolationSearch(arr, n, x);
	float t2 = clock();
	float RunTime= (t2 - t1) / (double) CLOCKS_PER_SEC;
	printf("\nTime taken: %.8f", RunTime );
	return 0;
}
