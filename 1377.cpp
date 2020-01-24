// time: O(nlogn+n)
// memory: O(n) to store the given array
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<pair<int,int> > a, int n) {
	int answer=0;
	sort(a.begin(), a.end());
	for(int i=0; i<n; i++) {
		if(a[i].second - i > answer) answer = a[i].second-i;
	}
	return answer+1;
}

int main() {
	int n;
	scanf("%d", &n);
	vector<pair<int,int> > arr(n);
	for(int i=0; i<n; i++) {
		scanf("%d", &arr[i].first);
		arr[i].second = i;
	}
	printf("%d", solution(arr, n));
	return 0;
}