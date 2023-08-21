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
	for(int i = 0 ; i < n; i++) {
		cin >> nums[i];
	}
	sort(nums.begin(), nums.end());
	ll sum = 0;
	bool found = false;
	for(int i = 0; i < n; i++) {
		if(nums[i] > sum+1) {
			found = true;
			cout << sum+1 << "\n";
			break;
		}
		else {
			sum += nums[i];
		}
	}
	if(!found)
		cout << sum+1 << "\n";
}