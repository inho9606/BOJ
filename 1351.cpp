#include <iostream>
#include <map>
using namespace std;
map<long long, long long> f;
long long cal(long long n, long long p, long long q) {
	if (f.count(n) >= 1)
		return f[n];
	else
		return f[n] = cal(n / p, p, q) + cal(n / q, p, q);
}
int main() {
	long long n, p, q;
	cin.tie(0);
	cin >> n >> p >> q;
	f[0] = 1;
	cout << cal(n, p, q);
	return 0;
}