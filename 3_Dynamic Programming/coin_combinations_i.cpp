#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
constexpr int MOD = 1e9+7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, x;
	cin >> n >> x;
	vector<int> nums(n);
	for(int i = 0; i < n; i++)
		cin >> nums[i];
	
	vector<int> dp(x+1, 0);
	dp[0] = 1;
	for(int i = 1; i <= x; i++) {
		for(int num : nums) {
			if(i-num>=0)
				dp[i] = (dp[i]+dp[i-num])%MOD;
		}
	}
	cout << dp[x] << "\n";
}