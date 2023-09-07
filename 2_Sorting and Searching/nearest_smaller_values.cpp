#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

void update(int pos, int id, vector<int>& tree) {
	int n = (int)tree.size()/2;
	pos += n;
	while(pos > 0) {
		tree[pos] = max(tree[pos], id);
		pos >>= 1;
	}
}

int query(int l, int r, vector<int>& tree) {
	int n = (int)tree.size()/2;
	l+=n;
	r+=n;
	int ans = 0;
	for(; l <= r; l>>=1, r>>=1) {
		if(l%2==1) {
			ans = max(ans, tree[l]);
			l++;
		}
		if(r%2==0) {
			ans = max(ans, tree[r]);
			r--;
		}
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> nums(n);
	vector<int> seen;
	for(int i = 0; i < n; i++) {
		cin >> nums[i];
		seen.push_back(nums[i]);
	}
	sort(seen.begin(), seen.end());
	seen.erase(unique(seen.begin(), seen.end()), seen.end());
	vector<int> tree(seen.size()*2, 0);
	for(int i = 0; i < n; i++) {
		nums[i] = (int)(lower_bound(seen.begin(), seen.end(), nums[i])-seen.begin());
		cout << query(0, nums[i]-1, tree) << " ";
		update(nums[i], i+1, tree);
	}
	cout << "\n";
}