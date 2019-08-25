#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
	int n, c, s = 1;
	stack<int> st;
	vector<char> result;
	st.push(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> c;
		for (; s <= c; s++) {
			st.push(s);
			result.push_back('+');
		}
		if (c < st.top()) {
			cout << "NO\n";
			return 0;
		}
		for (; st.top() >= c; st.pop()) {
			result.push_back('-');
		}
	}
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << "\n";
	return 0;
}