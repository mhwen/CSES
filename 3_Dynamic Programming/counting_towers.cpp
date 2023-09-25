#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
constexpr ll MOD = 1e9+7;

/*


|   |   0

 _ _
|   | 	1

 _ _
| | |	2

 _
| | |	3
 
   _
| | |	4


| | |   5

Transitions:
0 from 0,1,2
1 from 0,1,2
2 from 1,2,3,4,5
3 from 1,2,3,4,5
4 from 1,2,3,4,5
5 from 1,2,3,4,5

*/

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<vector<ll>> dp(1e6+1, vector<ll>(6));
	dp[0][1] = 1;
	for(int i = 1; i < (int)dp.size(); i++) {
		dp[i][0] = dp[i][1] = (dp[i-1][0]+dp[i-1][1]+dp[i-1][2])%MOD;
		dp[i][2] = dp[i][3] = dp[i][4] = dp[i][5] = (dp[i-1][1]+dp[i-1][2]+dp[i-1][3]+dp[i-1][4]+dp[i-1][5])%MOD;
	}
	int t;
	cin >> t;
	while(t-->0) {
		int n;
		cin >> n;
		cout << (dp[n][1]+dp[n][2])%MOD << "\n";
	}
}