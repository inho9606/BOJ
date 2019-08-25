#include <iostream>
#include <queue>
#define MAX 100001
using namespace std;
int dist[MAX];

int solution(int n, int k) {
	queue<int> path;
	dist[n] = 0;
	path.push(n);
	while(path.empty() != 1) {
		if(path.front() + 1 < MAX && dist[path.front()+1] == -1) {
			dist[path.front()+1] = dist[path.front()]+1;
			path.push(path.front()+1);
		}
		if(path.front() - 1 >= 0 && dist[path.front()-1] == -1) {
			dist[path.front()-1] = dist[path.front()] +1;
			path.push(path.front()-1);
		}
		if(path.front() * 2 < MAX && dist[path.front()*2] == -1) {
			dist[path.front()*2] = dist[path.front()] +1;
			path.push(path.front()*2);
		}
		if(path.front() == k) break;
		else {
			path.pop();
		}
	}
	return dist[k];
}

int main() {
	int n, k;
	cin.tie(0);
	cin >> n >> k;
	for(int i=0; i<MAX; i++)
		dist[i] = -1;
	cout << solution(n, k);
	return 0;
}