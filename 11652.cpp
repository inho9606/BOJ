#include <iostream>
#include <algorithm>
using namespace std;
long long card[1000000];

int main() {
	int n, l=0, cnt=1;
	long long m;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> card[i];
	sort(card, card+n);
	m = card[0];
	for(int i=1; i<n; i++) {
		if(card[i] == card[i-1]) cnt++;
		else {
			if(cnt > l) {
				m = card[i-1];
				l = cnt;
			}
			cnt = 1;
		}
		if(i == n-1 && cnt > l) m = card[i];
	}
	cout << m;
	return 0;
}