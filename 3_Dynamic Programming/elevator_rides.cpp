#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
constexpr ll INF = 1e18;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	ll x;
	cin >> n >> x;
	vector<ll> weights(n);
	for(int i = 0; i < n; i++) {
		cin >> weights[i];
	}
	vector<pair<int, ll>> dp(1<<n, {n, INF});
	dp[0] = {1, 0};
	for(int mask = 0; mask < 1<<n; mask++) {
		for(int b = 0; b < n; b++) {
			if(mask&(1<<b)) {
				dp[mask] = min(dp[mask], {dp[mask^(1<<b)].first+1, weights[b]});
				if(dp[mask^(1<<b)].second+weights[b]<=x)
					dp[mask] = min(dp[mask], {dp[mask^(1<<b)].first, dp[mask^(1<<b)].second+weights[b]});
			}
		}
	}
	cout << dp[(1<<n)-1].first << "\n";
}