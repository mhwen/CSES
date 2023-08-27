#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	map<int, int> seen;
	int left = 0;
	int best = 0;
	for(int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		left = max(left, seen[x]);
		best = max(best, i-left);
		seen[x] = i;
	}
	cout << best << "\n";
}