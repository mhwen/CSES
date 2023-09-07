#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

bool possible(ll maxSum, int k, vector<ll>& nums) {
	int count = 1;
	ll sum = 0;
	for(ll i : nums) {
		if(i > maxSum)
			return false;
		sum += i;
		if(sum > maxSum) {
			count++;
			sum = i;
		}
	}
	return count <= k;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k;
	cin >> n >> k;
	vector<ll> nums(n);
	for(int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	ll left = 0, right = 1e18;
	while(left < right) {
		ll mid = (left+right)/2;
		if(!possible(mid, k, nums))
			left = mid+1;
		else
			right = mid;
	}
	cout << left << "\n";
}