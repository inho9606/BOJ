#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
int answer = INT_MIN;
void solution(vector<char>& e, int v, int p) {
	if(p==e.size()-1) {
		if(v>answer) answer=v;
		return;
	}
	if(e[p+1] == '+') solution(e, v+e[p+2]-48, p+2);
	else if(e[p+1] == '-') solution(e, v-e[p+2]+48, p+2);
	else if(e[p+1] == '*') solution(e, v*(e[p+2]-48), p+2);
	if(e.size()-p > 4) {
		int t;
		if(e[p+3] == '+') t = e[p+2] + e[p+4] - 96; 
		else if(e[p+3] == '-') t = e[p+2] - e[p+4];
		else if(e[p+3] == '*') t = (e[p+2] - 48) * (e[p+4] - 48);
		if(e[p+1] == '+') solution(e, v+t, p+4);
		else if(e[p+1] == '-') solution(e, v-t, p+4);
		else if(e[p+1] == '*') solution(e, v*t, p+4);
	}

}
int main() {
	cin.tie(0);
	int n, t;
	cin >> n;
	vector<char> equation(n);
	for(int i=0; i<n; i++)
		cin >> equation[i];
	solution(equation, equation[0]-48, 0);
	printf("%d", answer);
	return 0;
}