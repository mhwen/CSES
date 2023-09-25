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
	vector<int> best(n+1, 2e9);
	best[0] = 0;
	int ans = 0;
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		auto it = lower_bound(best.begin(), best.end(), x);
		int len = (int)(it-best.begin()-1);
		best[len+1] = x;
		ans = max(ans, len+1);
	}
	cout << ans << "\n";
}