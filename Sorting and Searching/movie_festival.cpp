#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<pair<int, int>> intervals;
	for(int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		intervals.push_back({b, a});
	}
	sort(intervals.begin(), intervals.end());
	int count = 0;
	int end = 0;
	for(auto& i : intervals) {
		if(i.second >= end) {
			end = i.first;
			count++;
		}
	}
	cout << count << "\n";
}