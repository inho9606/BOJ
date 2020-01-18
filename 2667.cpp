// time: O(n^2) for searching given map
// time: O(n) for counting the connected houses
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

void solution(string* m, int n) {
	vector<int> house;
	int cnt, x, y;
	queue<pair<int, int> > bfs;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if(m[i][j] == 49) {
				bfs.push({i,j});
				m[i][j] = 50;
				cnt = 1;
				while(bfs.empty() == 0) {
					y = bfs.front().first;
					x = bfs.front().second;
					bfs.pop();
					if(x != n-1 && m[y][x+1] == 49) {
						m[y][x+1] = 50;
						bfs.push({y, x+1});
						cnt++;
					}
					if(x != 0 && m[y][x-1] == 49) {
						m[y][x-1] = 50;
						bfs.push({y, x-1});
						cnt++;
					}
					if(y != n-1 && m[y+1][x] == 49) {
						m[y+1][x] = 50;
						bfs.push({y+1, x});
						cnt++;
					}
					if(y != 0 && m[y-1][x] == 49) {
						m[y-1][x] = 50;
						bfs.push({y-1, x});
						cnt++;
					}
				}
				house.push_back(cnt);
			}
		}
	}
	sort(house.begin(), house.end());
	printf("%d\n", house.size());
	for(int i=0; i<house.size(); i++)
		printf("%d\n", house[i]);
}

int main() {
	int n;
	cin >> n;
	string* m = new string[n];
	cin.tie(0);
	for (int i = 0; i < n; i++)
		cin >> m[i];
	solution(m, n);
	delete[] m;
	return 0;
}