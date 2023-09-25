#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll calc(ll a, vector<vector<ll>>& dp) {
	if(a < 0)
		return 0;
	if(a == (ll)1e18)
		a--;
	vector<int> digits;
	while(a > 0) {
		digits.push_back((int)(a%10));
		a /= 10;
	}
	int digs = (int)digits.size();
	ll res = 0;
	for(int i = 0; i < digs-1; i++) {
		res += dp[i][0];
	}
	digits.push_back(-1);
	bool allGood = true;
	for(int i = digs-1; i >= 0; i--) {
		for(int j = 0; j < digits[i]; j++) {
			if(j == digits[i+1])
				continue;
			res += dp[i][j];
		}
		if(digits[i] == digits[i+1]) {
			allGood = false;
			break;
		}
	}
	if(allGood)
		res++;
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<vector<ll>> dp(18, vector<ll>(10));
	fill(dp[0].begin(), dp[0].end(), 1);
	for(int i = 1; i < 18; i++) {
		for(int to = 0; to < 10; to++) {
			for(int from = 0; from < 10; from++) {
				if(to == from)
					continue;
				dp[i][to] += dp[i-1][from];
			}
		}
	}
	ll a, b;
	cin >> a >> b;
	cout << calc(b, dp)-calc(a-1, dp) << "\n";
}