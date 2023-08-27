#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int n;

void update(int l, int r, ll val, vector<ll>& tree) {
	l += n;
	r += n;
	for(; l <= r; l>>=1, r>>=1) {
		if(l%2==1) {
			tree[l] += val;
			l++;
		}
		if(r%2==0) {
			tree[r] += val;
			r--;
		}
	}
}

ll query(int pos, vector<ll>& tree) {
	int id = pos+n;
	ll sum = 0;
	while(id > 0) {
		sum += tree[id];
		id >>= 1;
	}
	return sum;
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
		update(i, i, a, tree);
	}
	for(int i = 0; i < q; i++) {
		int type;
		cin >> type;
		if(type == 1) {
			int a, b, u;
			cin >> a >> b >> u;
			update(a-1, b-1, u, tree);
		}
		else {
			int k;
			cin >> k;
			cout << query(k-1, tree) << "\n";
		}
	}
}