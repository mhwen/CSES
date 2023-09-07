#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	ll x;
	cin >> n >> x;
	vector<ll> nums(n);
	for(int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	int right = 0;
	ll sum = 0;
	ll ans = 0;
	for(int left = 0; left < n; left++) {
		while(right < n && sum+nums[right] <= x) {
			sum += nums[right];
			right++;
		}
		if(sum == x)
			ans++;
		sum -= nums[left];
	}
	cout << ans << "\n";
}