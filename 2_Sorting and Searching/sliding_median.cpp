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
	multiset<int> window;
	vector<int> nums(n);
	for(int i = 0; i < n; i++) {
		cin >> nums[i];
		if(i < k)
			window.insert(nums[i]);
	}

	auto median = next(window.begin(), (k-1)/2);
	cout << *median;
	for(int i = k; i < n; i++) {
		window.insert(nums[i]);
		if(nums[i] < *median)
			median--;
		if(nums[i-k] <= *median)
			median++;
		window.erase(window.find(nums[i-k]));
		cout << " " << *median;
	}
	cout << "\n";
}