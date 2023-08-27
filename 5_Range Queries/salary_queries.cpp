#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef long long ll;

int N;

ll query(int l, int r, vector<ll>& tree) {
	ll sum = 0;
	l += N;
	r += N;
	for(; l <= r; l >>= 1, r >>= 1) {
		if(l%2==1) {
			sum += tree[l];
			l++;
		}
		if(r%2==0) {
			sum += tree[r];
			r--;
		}
	}
	return sum;
}

void update(int pos, ll val, vector<ll>& tree) {
	int id = pos+N;
	while(id > 0) {
		tree[id] += val;
		id >>= 1;
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, q;
	cin >> n >> q;
	vector<int> salaries(n);
	vector<int> seen;
	for(int i = 0; i < n; i++) {
		cin >> salaries[i];
		seen.push_back(salaries[i]);
	}
	vector<bool> qtype(q);
	vector<pair<int, int>> queries(q);

	for(int i = 0; i < q; i++) {
		char type;
		int a, b;
		cin >> type >> a >> b;
		qtype[i] = type == '?';
		queries[i] = {a, b};
		seen.push_back(b);
		if(qtype[i])
			seen.push_back(a);
	}
	sort(seen.begin(), seen.end());
	seen.erase(unique(seen.begin(), seen.end()), seen.end());
	N = (int)seen.size();
	map<int, int> compress;
	int index = 0;
	for(int i : seen) {
		compress[i] = index++;
	}
	vector<ll> tree(2*N);
	for(int i = 0; i < n; i++) {
		salaries[i] = compress[salaries[i]];
		update(salaries[i], 1, tree);
	}
	for(int i = 0; i < q; i++) {
		int a = queries[i].first;
		int b = queries[i].second;
		if(qtype[i]) {
			cout << query(compress[a], compress[b], tree) << "\n";
		}
		else {
			update(salaries[a-1], -1, tree);
			salaries[a-1] = compress[b];
			update(salaries[a-1], 1, tree);
		}
	}
	
}