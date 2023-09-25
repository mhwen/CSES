#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
constexpr ll MOD = 1e9+7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	vector<vector<ll>> dp(n+1, vector<ll>(m+1));
	for(int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		for(int j = 1; j <= m; j++) {
			if(x == 0 || x == j) {
				if(i == 1) {
					dp[i][j] = 1;
					continue;
				}
				dp[i][j] += dp[i-1][j];
				if(j > 1)
					dp[i][j] += dp[i-1][j-1];
				if(j < m)
					dp[i][j] += dp[i-1][j+1];
				dp[i][j] %= MOD;
			}
		}
	}
	ll ans = 0;
	for(int i = 1; i <= m; i++)
		ans += dp[n][i];
	ans %= MOD;
	cout << ans << "\n";
}