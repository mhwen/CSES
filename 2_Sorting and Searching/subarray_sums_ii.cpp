#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	ll x;
	cin >> n >> x;
	map<ll, int> counts;
	ll sum = 0;
	ll ans = 0;
	for(int i = 0; i < n; i++) {
		counts[sum]++;
		ll a;
		cin >> a;
		sum += a;
		if(counts.count(sum-x))
			ans += counts[sum-x];
	}
	cout << ans << "\n";
	
}