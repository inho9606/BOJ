#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 2001
using namespace std;
bool visit[MAX][MAX];

int solution(int k) {
	int tmp = 0;
	int number, key, clip;
	queue<pair<pair<int, int>, int> > sticker;
	sticker.push({ {1, 0}, 0 });
	dist[1] = 0;
	visit[1][0] = 1;
	while(sticker.empty() == 0) {
		number = sticker.front().first.first;
		key = sticker.front().first.second;
		clip = sticker.front().second;
		if(number == k) return key;
		if(number > 0 && number < MAX) {
			if(visit[number-1][clip] == 0) {
				sticker.push({{number-1,key+1}, clip});
				visit[number-1][clip] = 1;
			}
			if(visit[number][number] == 0) {
				sticker.push({{number,key+1},number});
				visit[number][number] = 1;
			}
		}
		if(clip > 0 && number+clip < MAX && visit[number+clip][clip] == 0) {
			sticker.push({ {number + clip, key+1}, clip});
			visit[number+clip][clip] = 1;
		}
		sticker.pop();
	}
	return -1;
}

int main() {
	int s;
	cin.tie(0);
	cin >> s;
	cout << solution(s);
	return 0;
}