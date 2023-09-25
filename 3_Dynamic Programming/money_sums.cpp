#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<bool> pos(1000*n+1);
	pos[0] = true;
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		for(int j = (int)pos.size()-1; j >= x; j--) {
			pos[j] = pos[j]|pos[j-x];
		}
	}
	vector<int> ans;
	for(int i = 1; i < (int)pos.size(); i++) {
		if(pos[i])
			ans.push_back(i);
	}
	cout << ans.size() << "\n";
	for(int i : ans)
		cout << i << " ";
	cout << "\n";
}