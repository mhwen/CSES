#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
constexpr int INF = 1e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s1, s2;
	cin >> s1 >> s2;
	vector<vector<int>> dp(s1.length()+1, vector<int>(s2.length()+1, INF));
	dp[0][0] = 0;
	for(int i = 0; i <= (int)s1.length(); i++) {
		for(int j = 0; j <= (int)s2.length(); j++) {
			if(i > 0)
				dp[i][j] = min(dp[i][j], dp[i-1][j]+1);
			if(j > 0)
				dp[i][j] = min(dp[i][j], dp[i][j-1]+1);
			if(i > 0 && j > 0)
				dp[i][j] = min(dp[i][j], dp[i-1][j-1]+ (s1[i-1] == s2[j-1] ? 0 : 1));
				
		}
	}
	cout << dp[s1.length()][s2.length()] << "\n";
}