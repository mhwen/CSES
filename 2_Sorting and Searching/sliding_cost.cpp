#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k;
	cin >> n >> k;
	multiset<ll> window;
	vector<ll> nums(n);
	for(int i = 0; i < n; i++) {
		cin >> nums[i];
		if(i < k)
			window.insert(nums[i]);
	}

	auto median = next(window.begin(), (k-1)/2);
	ll cost = 0;
	for(int i = 0; i < k; i++) {
		cost += abs(nums[i]-*median);
	}
	cout << cost;
	for(int i = k; i < n; i++) {
		ll oldMedian = *median;
		window.insert(nums[i]);
		if(nums[i] < *median)
			median--;
		if(nums[i-k] <= *median)
			median++;
		if(k%2==1)
			cost += abs(*median-oldMedian);
		else {
			if(*median < oldMedian)
				cost += 2*(oldMedian-*median);
		}

		cost += abs(nums[i]-*median);
		cost -= abs(nums[i-k]-*median);
		window.erase(window.find(nums[i-k]));
		cout << " " << cost;
	}
	cout << "\n";
}