#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	ll sum = 0;
	ll best = -1e9;
	for(int i = 0; i < n; i++) {
		ll x;
		cin >> x;
		sum = max(sum+x, x);
		best = max(best, sum);
	}
	cout << best << "\n";
}