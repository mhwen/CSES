#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

void update(int pos, int val, vector<int>& tree) {
	int n = (int)tree.size()/2;
	pos += n;
	tree[pos] = val;
	pos >>= 1;
	while(pos > 0) {
		tree[pos] = min(tree[pos*2], tree[pos*2+1]);
		pos >>= 1;
	}
}

int query(int l, int r, vector<int>& tree) {
	int n = (int)tree.size()/2;
	l+=n; r+=n;
	int ans = tree[l];
	for(; l <= r; l>>=1, r>>=1) {
		if(l%2==1)
			ans = min(ans, tree[l++]);
		if(r%2==0)
			ans = min(ans, tree[r--]);
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, q;
	cin >> n >> q;
	vector<int> orderFromRight(2*n);
	vector<int> orderFromLeft(2*n);
	for(int i = 0; i < n; i++) {
		int p;
		cin >> p;
		update(i, p+i, orderFromRight);
		update(i, p+n-i, orderFromLeft);
	}

	while(q-->0) {
		int type, k;
		cin >> type >> k;
		k--;
		if(type == 1) {
			int x;
			cin >> x;
			update(k, x+k, orderFromRight);
			update(k, x+n-k, orderFromLeft);
		}
		else {
			int fromRight = query(k, n-1, orderFromRight)-k;
			int fromLeft = query(0, k, orderFromLeft)-(n-k);
			cout << min(fromRight, fromLeft) << "\n";
		}
	}
}