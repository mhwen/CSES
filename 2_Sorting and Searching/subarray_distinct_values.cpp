#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k;
	cin >> n >> k;
	map<int, int> counts;
	vector<int> nums(n);
	int left = 0;
	int unique = 0;
	ll ans = 0;
	for(int i = 0; i < n; i++) {
		cin >> nums[i];
		if(++counts[nums[i]]==1)
			unique++;
		while(unique > k) {
			if(--counts[nums[left++]]==0)
				unique--;
		}
		ans += i-left+1;
	}
	cout << ans << "\n";
}