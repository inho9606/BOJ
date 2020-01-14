// time: O(m+n+d/b)
#pragma warning(disable: 4996) 
#include <cstdio>
#include <stack>
using namespace std;

// time: O(n)
int decimal(int* A, int n, int a) {
	int answer=0, t=1;
	for(int i=n-1; i>=0; i--) {
		answer += A[i]*t;
		t *= a;
	}
	return answer;
}

// time: O(d/b)
void changeToB(int n, int b) {
	stack<int> B;
	for(int i=n; i>0; i/=b)
		B.push(i%b);
	while(B.empty() == 0) {
		printf("%d ", B.top());
		B.pop();
	}
}

int main() {
	int a,b,m, d;
	scanf("%d%d%d", &a, &b, &m);
	int* A = new int[m];
	for(int i=0; i<m; i++)
		scanf("%d", &A[i]);
	d = decimal(A, m, a);
	delete[] A;
	changeToB(d, b);
	return 0;
}