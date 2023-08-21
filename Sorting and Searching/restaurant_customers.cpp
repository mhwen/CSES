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
	vector<pair<int, int>> times;
	for(int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		times.push_back({a, 1});
		times.push_back({b, -1});
	}
	sort(times.begin(), times.end());
	int count = 0;
	int best = 0;
	for(auto& t : times) {
		count += t.second;
		best = max(best, count);
	}
	cout << best << "\n";
}