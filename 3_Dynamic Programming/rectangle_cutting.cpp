#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
constexpr int INF = 1e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a, b;
	cin >> a >> b;
	vector<vector<int>> dp(a+1, vector<int>(b+1, INF));
	for(int i = 1; i <= a; i++) {
		for(int j = 1; j <= b; j++) {
			if(i == j)
				dp[i][j] = 0;
			else {
				for(int h = 1; h < i; h++)
					dp[i][j] = min(dp[i][j], dp[h][j]+dp[i-h][j]+1);
				for(int h = 1; h < j; h++)
					dp[i][j] = min(dp[i][j], dp[i][h]+dp[i][j-h]+1);
			}
		}
	}
	cout << dp[a][b] << "\n";
}