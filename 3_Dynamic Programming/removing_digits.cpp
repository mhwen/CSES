#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
constexpr int INF = 1e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> dp(n+1, INF);
	dp[0] = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = i; j > 0; j/=10)
			dp[i] = min(dp[i], dp[i-j%10]+1);
	}
	cout << dp[n];
}