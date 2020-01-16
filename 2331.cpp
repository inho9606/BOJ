#pragma warning(disable: 4996) 
#include <cstdio>
#include <math.h>
using namespace std;
int visited[250000];

int solution(int n, int p) {
	int cnt, answer=0, t=0;
	visited[n] = 1;
	cnt = 1;
	while(visited[n] < 3) {
		t = 0;
		for(int i=n; i>0; i/=10)
			t += pow(i%10, p);
		n = t;
		if(visited[n] == 0) cnt++;
		visited[n] += 1;
	}
	for(int i=0; i<250000; i++)
		if(visited[i] == 1) answer+=1;
	return answer;
}

int main() {
	int n, p;
	scanf("%d%d", &n, &p);
	printf("%d", solution(n, p));
	return 0;
}