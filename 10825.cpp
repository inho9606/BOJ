#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
typedef struct st {
	string name;
	int kor, eng, math;
};
bool comp(const st& a, const st&b) {
	if(a.kor != b.kor) return a.kor > b.kor;
	if(a.eng != b.eng) return a.eng < b.eng;
	if(a.math != b.math) return a.math > b.math;
	return a.name < b.name;

}

int main() {
	int n;
	cin.tie(0);
	cin >> n;
	st* v = new st[n];
	for(int i=0; i<n; i++)
		cin >> v[i].name >> v[i].kor >> v[i].eng >> v[i].math;
	sort(v, v+n, comp);
	for(int i=0; i<n; i++)
		cout << v[i].name << "\n";
	delete[] v;
	return 0;
}