// time: O(nLogn + mLogn)
// space: O(n)
#include <cstdio>
#include <algorithm>
using namespace std;
int card[500000];

int solution(int left, int right, int n) {
	int mid;
	while(left<=right) {
		mid = (left+right)/2;
		if(card[mid] == n) return 1;
		else if(n < card[mid]) right = mid-1;
		else if(n > card[mid]) left = mid+1;
	}
	return 0;
}

int main() {
	int n, m, x;
	scanf("%d", &n);
	for(int i=0; i<n;i++)
		scanf("%d", &card[i]);
	sort(card, card+n);
	scanf("%d", &m);
	for(int i=0; i<m; i++) {
		scanf("%d", &x);
		printf("%d ", solution(0, n-1, x));
	}
	return 0;
}