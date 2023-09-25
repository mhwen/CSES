#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while(t-->0) {
		int n;
		cin >> n;
		int xr = 0;
		for(int i = 0; i < n; i++) {
			int x;
			cin >> x;
			xr ^= x;
		}
		if(xr)
			cout << "first\n";
		else
			cout << "second\n";
	}
}