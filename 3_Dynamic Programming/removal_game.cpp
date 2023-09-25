#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<ll> nums(n);
	vector<ll> sum(n+1);
	for(int i = 0; i < n; i++) {
		cin >> nums[i];
		sum[i+1] = nums[i]+sum[i];
	}
	vector<vector<ll>> dp(n, vector<ll>(n));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j+i<n; j++) {
			int left = j;
			int right = j+i;
			if(left == right)
				dp[left][right] = nums[j];
			else {
				dp[left][right] = max(
					nums[left]+(sum[right+1]-sum[left+1]-dp[left+1][right]),
					nums[right]+(sum[right]-sum[left]-dp[left][right-1])
				);
			}
		}
	}
	cout << dp[0][n-1] << "\n";
	
}