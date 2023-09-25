#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int query(int val, vector<int>& tree) {
	int n = (int)tree.size()/2;
	int pos = 1;
	while(pos < n) {
		if(tree[pos*2] >= val)
			pos = pos*2;
		else
			pos = pos*2+1;
	}
	if(tree[pos] < val)
		return -1;
	return pos-n;
}

void update(int pos, int diff, vector<int>& tree) {
	int n = (int)tree.size()/2;
	pos += n;
	tree[pos] += diff;
	pos >>= 1;
	while(pos > 0) {
		tree[pos] = max(tree[pos*2], tree[pos*2+1]);
		pos >>= 1;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	int pow = 1;
	while(pow < n)
		pow *= 2;
	vector<int> tree(2*pow);
	for(int i = 0; i < n; i++) {
		int h;
		cin >> h;
		update(i, h, tree);
	}
	for(int i = 0; i < m; i++) {
		int r;
		cin >> r;
		int room = query(r, tree);
		cout << room+1 << " ";
		if(room != -1)
			update(room, -r, tree);
	}
	cout << "\n";
}