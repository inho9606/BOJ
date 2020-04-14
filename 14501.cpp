#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int>& t, vector<int>& p) {
	int n = t.size();
	vector<int> f(n+1, 0);
	for(int i=1; i<=n; i++) {
		for(int j=0; j<i; j++) {
			if(f[j] > f[i]) f[i] = f[j];
			if(j+t[j] == i && f[j]+p[j] > f[i]) f[i] = f[j] + p[j];
		}
	}
	return f[n];
}
int main() {
	int n;
	cin.tie(0);
	cin >> n;
	vector<int> t(n), p(n);
	for(int i=0; i<n; i++)
		cin >> t[i] >> p[i];
	printf("%d", solution(t, p));
	return 0;
}