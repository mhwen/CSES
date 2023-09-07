#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	ll x;
	cin >> n >> x;
	vector<ll> nums(n);
	vector<int> ans;
	map<ll, pair<int, int>> seen;
	for(int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	for(int i = 0; i < n; i++) {
		for(int j = i+1; j < n; j++) {
			if(seen.count(x-nums[i]-nums[j])) {
				ans.push_back(seen[x-nums[i]-nums[j]].first);
				ans.push_back(seen[x-nums[i]-nums[j]].second);
				ans.push_back(i+1);
				ans.push_back(j+1);
				goto A;
			}
		}
		for(int j = 0; j < i; j++) {
			seen[nums[j]+nums[i]] = {j+1, i+1};
		}
	}
	A:
	if(ans.size())
		cout << ans[0] << " " << ans[1] << " " << ans[2] << " " << ans[3] << "\n";
	else
		cout << "IMPOSSIBLE\n";
}