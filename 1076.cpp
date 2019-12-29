#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	cin.tie(0);
	map<string,pair<int,int> > color;
	unsigned long long om = 0;
	string input;
	color["black"] = {0, 1};
	color["brown"] = {1, 10};
	color["red"] = {2, 100};
	color["orange"] = {3, 1000};
	color["yellow"] = {4, 10000};
	color["green"] = {5, 100000};
	color["blue"] = {6, 1000000};
	color["violet"] = {7, 10000000};
	color["grey"] = {8, 100000000};
	color["white"] = {9, 1000000000};
	cin >> input;
	om += color[input].first * 10;
	cin >> input;
	om += color[input].first;
	cin >> input;
	om *= color[input].second;
	cout << om;
	return 0;
}