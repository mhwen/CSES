#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
constexpr int MOD = 1e9+7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, x;
	cin >> n >> x;
	vector<int> prev(x+1, 0);
	vector<int> dp(x+1, 0);
	prev[0] = 1;
	for(int i = 1; i <= n; i++) {
		int c;
		cin >> c;
		for(int j = 0; j <= x; j++) {
			dp[j] = prev[j];
			if(j-c >= 0) {
				dp[j] += dp[j-c];
			}
			dp[j] %= MOD;
		}
		swap(prev, dp);
	}
	cout << prev[x] << "\n";
}