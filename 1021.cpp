#include <deque>
using namespace std;

int main() {
	int n, m, x, count=0;
	deque<int> dq;
	cin.tie(0);
	cin >> n >> m;
	for(int i=1; i<=n; i++)
		dq.push_back(i);
	for(int i=0; i<m; i++) {
		cin >> x;
		for(int j=0; j<dq.size(); j++) {
			if(dq[j] == x) {
				if(j < dq.size() -j) {
					count += j;
					for(int k=0; k<j; k++) {
						dq.push_back(dq.front());
						dq.pop_front();
					}
				}
				else {
					count += dq.size() - j;
					for(int k=0; k<dq.size()-j; k++) {
						dq.push_front(dq.back());
						dq.pop_back();
					}
				}
			dq.pop_front();
			break;
			}
		}
	}
	cout << count;
	return 0;
}