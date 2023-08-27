#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int n;

ll query(int l, int r, vector<ll>& tree) {
	ll ans = 1e9;
	l += n;
	r += n;
	for(; l <= r; l>>=1, r>>=1) {
		if(l%2==1) {
			ans = min(ans, tree[l]);
			l++;
		}
		if(r%2==0) {
			ans = min(ans, tree[r]);
			r--;
		}
	}
	return ans;
}

void update(int pos, ll val, vector<ll>& tree) {
	int id = pos+n;
	tree[id] = val;
	id >>= 1;
	while(id > 0) {
		tree[id] = min(tree[id*2], tree[id*2+1]);
		id >>= 1;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int q;
	cin >> n >> q;
	vector<ll> nums(n);
	vector<ll> tree(2*n);
	for(int i = 0; i < n; i++) {
		int a;
		cin >> a;
		update(i, a, tree);
	}
	for(int i = 0; i < q; i++) {
		int type;
		cin >> type;
		if(type == 1) {
			int k, u;
			cin >> k >> u;
			update(k-1, u, tree);
		}
		else {
			int a, b;
			cin >> a >> b;
			cout << query(a-1, b-1, tree) << "\n";
		}
	}
}