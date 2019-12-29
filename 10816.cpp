// time: O(nLogn +m2Logn)
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, m, x;
	scanf("%d", &n);
	vector<int> card(n);
	for(int i=0; i<n;i++)
		scanf("%d", &card[i]);
	sort(card.begin(), card.end());
	scanf("%d", &m);
	for(int i=0; i<m; i++) {
		scanf("%d", &x);
		printf("%d ", upper_bound(card.begin(), card.end(), x) - lower_bound(card.begin(), card.end(), x));
	}
	return 0;
}