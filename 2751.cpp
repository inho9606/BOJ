#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, temp;
	scanf("%d", &n);
	int* arr = new int[n];
	for(int i=0; i<n; i++)
		scanf("%d", &arr[i]);
//	for(int i=0; i<n-1; i++) {
//		for(int j=i+1; j<n; j++) {
//			if(arr[i] > arr[j]) {
//				temp = arr[i];
//				arr[i] = arr[j];
//				arr[j] = temp;
//			}
//		}
//	}
	sort(arr, arr+n);
	for(int i=0; i<n; i++)
		printf("%d\n", arr[i]);
	delete[] arr;
	return 0;
}