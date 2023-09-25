#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, x;
	cin >> n >> x;
	vector<vector<int>> dp(n+1, vector<int>(x+1));
	vector<int> prices(n);
	vector<int> pages(n);
	for(int i = 0; i < n; i++) {
		cin >> prices[i];
	}
	for(int i = 0; i < n; i++) {
		cin >> pages[i];
	}
	int best = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j <= x; j++) {
			dp[i+1][j] = dp[i][j];
			if(prices[i] <= j)
				dp[i+1][j] = max(dp[i+1][j], dp[i][j-prices[i]]+pages[i]);
		}
	}
	for(int i = 0; i <= x; i++)
		best = max(best, dp[n][i]);
	cout << best << "\n";
	
}