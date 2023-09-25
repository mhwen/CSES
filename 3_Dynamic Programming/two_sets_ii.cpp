#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
constexpr ll MOD = 1e9+7;
constexpr ll INV2 = 5e8+4;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll n;
	cin >> n;
	vector<ll> dp(n*(n+1)/2+1);
	dp[0] = 1;
	for(ll i = 1; i <= n; i++) {
		for(ll j = n*(n+1)/2; j >= i; j--)
			dp[j] = (dp[j]+dp[j-i])%MOD;
	}
	if(n*(n+1)/2 % 2 == 0)
		cout << dp[n*(n+1)/4]*INV2%MOD << "\n";
	else
		cout << 0 << "\n";
}