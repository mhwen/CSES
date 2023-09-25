#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

void update(int pos, int diff, vector<int>& tree) {
	int n = (int)tree.size()/2;
	pos += n;
	while(pos > 0) {
		tree[pos] += diff;
		pos >>= 1;
	}
}

int query(int wanted, vector<int>& tree) {
	int n = (int)tree.size()/2;
	int pos = 1;
	while(pos < n) {
		if(tree[pos*2] >= wanted)
			pos = pos*2;
		else {
			wanted -= tree[pos*2];
			pos = pos*2+1;
		}
	}
	return pos-n;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	int amt = 1;
	while(amt < n)
		amt *= 2;
	vector<int> alive(2*amt);
	vector<int> nums(n);
	for(int i = 0; i < n; i++) {
		cin >> nums[i];
		update(i, 1, alive);
	}
	for(int i = 0; i < n; i++) {
		int q;
		cin >> q;
		int index = query(q, alive);
		cout << nums[index] << " ";
		update(index, -1, alive);
	}
	cout << "\n";
	
}