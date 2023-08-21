#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	multiset<int> towers;
	for(int i = 0; i < n; i++) {
		int k;
		cin >> k;
		auto it = towers.upper_bound(k);
		if(it != towers.end()) {
			towers.erase(it);
		}
		towers.insert(k);
	}
	cout << towers.size() << "\n";
}