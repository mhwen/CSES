#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, x;
	cin >> n >> x;
	vector<int> nums(n);
	map<int, int> seen;
	bool found = false;
	for(int i = 1; i <= n; i++) {
		cin >> nums[i];
		int needed = x-nums[i];
		if(seen.count(needed)) {
			found = true;
			cout << i << " " << seen[needed];
			break;
		}
		seen[nums[i]] = i;
	}
	if(!found)
		cout << "IMPOSSIBLE\n";
	
}