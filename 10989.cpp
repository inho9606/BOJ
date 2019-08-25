#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, temp;
	scanf("%d", &n);
	int* arr = new int[10001];
	for(int i=0; i<n; i++) {
		scanf("%d", &temp);
		arr[temp] += 1;
	}
//	sort(arr, arr+n);
	for(int i=1; i<10001; i++) {
		for(int j=0; j<arr[i]; j++)
		printf("%d\n", i);
	}
	delete[] arr;
	return 0;
}