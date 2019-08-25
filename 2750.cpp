#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n, temp;
	cin >> n;
	vector<int> arr(n);
	for(int i=0; i<n; i++)
		cin >> arr[i];
//	for(int i=0; i<n-1; i++) {
//		for(int j=i+1; j<n; j++) {
//			if(arr[i] > arr[j]) {
//				temp = arr[i];
//				arr[i] = arr[j];
//				arr[j] = temp;
//			}
//		}
//	}
	sort(arr.begin(), arr.end());
	for(int i=0; i<n; i++)
		cout << arr[i] << endl;
	return 0;
}