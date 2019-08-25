#include <iostream>
#include <math.h>
using namespace std;
int pages[10];

void solution(int s, int e) {
	for(int i=0; i<=e%10; i++) {
		pages[i] += 1;
	}
	for(int i=s/10; i>0; i/=10)
		pages[i%10] += e%10+1;
//	if(s/10 > 0) pages[s/10] += e%10+1;
	if(s/10 == 0) pages[0] -= 1;
}

int main() {
	int n, i, count=0;
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int j=n; j>0; j/=10) count++;
	count--;
	for(int j=1; j<=9; j++) {
		pages[j] = count * pow(10, count-1);
	}
	for(int j=1; j<count; j++) {
		pages[0] += 9 * j * pow(10, j-1);
	}
	for(i=pow(10, count); i<=n-10; i+=10)
		solution(i, i+9);
	solution(i, n%10);

	for(int i=0; i<10; i++)
		cout << pages[i] << " ";
	return 0;
}