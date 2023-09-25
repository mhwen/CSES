#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
constexpr int INF = 1e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, x;
	cin >> n >> x;
	vector<vector<int>> dp(n+1, vector<int>(x+1, INF));
	dp[0][0] = 0;
	for(int i = 1; i <= n; i++) {
		int c;
		cin >> c;
		for(int j = 0; j <= x; j++) {
			dp[i][j] = min(dp[i][j], dp[i-1][j]);
			if(j-c >= 0) {
				dp[i][j] = min(dp[i][j], dp[i-1][j-c]+1);
				dp[i][j] = min(dp[i][j], dp[i][j-c]+1);
			}
		}
	}
	if(dp[n][x] == INF)
		cout << -1 << "\n";
	else
		cout << dp[n][x] << "\n";
}