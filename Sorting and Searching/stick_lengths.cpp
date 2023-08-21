#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<ll> nums(n);
	for(int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	sort(nums.begin(), nums.end());
	ll curr = 0;
	for(int i = 0; i < n; i++) {
		curr += nums[i]-nums[0];
	}
	ll best = curr;
	for(int i = 1; i < n; i++) {
		curr -= (nums[i]-nums[i-1])*(n-2*i);
		best = min(best, curr);
	}
	cout << best << "\n";
	
}