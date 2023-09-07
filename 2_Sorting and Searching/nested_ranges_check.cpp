#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int query(int l, int r, vector<int>& tree) {
	int n = (int)tree.size()/2;
	l += n;
	r += n;
	int ans = 0;
	for(; l <= r; l>>=1, r>>=1) {
		if(l%2==1) {
			ans += tree[l];
			l++;
		}
		if(r%2==0) {
			ans += tree[r];
			r--;
		}
	}
	return ans;
}

void update(int pos, int val, vector<int>& tree) {
	int n = (int)tree.size()/2;
	pos += n;
	while(pos > 0) {
		tree[pos] += val;
		pos >>= 1;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> starts(n);
	vector<int> ends(n);
	vector<int> seen;
	for(int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		starts[i] = a;
		ends[i] = b;
		seen.push_back(a);
		seen.push_back(b);
	}
	seen.push_back(-1);
	sort(seen.begin(), seen.end());
	seen.erase(unique(seen.begin(), seen.end()), seen.end());
	vector<vector<int>> startEvents(seen.size());
	vector<vector<int>> endEvents(seen.size());
	for(int i = 0; i < n; i++) {
		int startIndex = (int)(lower_bound(seen.begin(), seen.end(), starts[i])-seen.begin());
		int endIndex = (int)(lower_bound(seen.begin(), seen.end(), ends[i])-seen.begin());
		starts[i] = startIndex;
		ends[i] = endIndex;
		startEvents[startIndex].push_back(i);
		endEvents[endIndex].push_back(i);
	}
	vector<int> active(seen.size()*2);
	vector<int> ended(seen.size()*2);
	vector<int> contains(n);
	vector<int> contained(n);
	for(int i = 0; i < (int)seen.size(); i++) {
		update(i, (int)startEvents[i].size(), active);
		for(int id : endEvents[i]) {
			update(starts[id], 1, ended);
		}
		
		for(int id : endEvents[i]) {
			contains[id] = query(starts[id], i, ended)-1;
			contained[id] = query(0, starts[id], active)-1;
		}
		
		for(int id : endEvents[i]) {
			update(starts[id], -1, active);
		}
	}
	
	for(int i : contains)
		cout << min(i, 1) << " ";
	cout << "\n";
	for(int i : contained)
		cout << min(i, 1) << " ";
	cout << "\n";
	
}