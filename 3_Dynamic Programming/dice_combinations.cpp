#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
constexpr ll MOD = 1e9+7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<ll> dp(n+1);
	dp[0] = 1;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; i-j >= 0 && j <= 6; j++)
			dp[i] += dp[i-j];
		dp[i] %= MOD;
	}
	cout << dp[n] << "\n";
}