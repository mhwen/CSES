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
	cin >> n;
	vector<int> counts(n);
	ll sum = 0;
	ll ans = 0;
	for(int i = 0; i < n; i++) {
		counts[sum%n]++;
		ll a;
		cin >> a;
		sum += a;
		sum %= n;
		if(sum < n)
			sum += n;
		ans += counts[sum%n];
	}
	cout << ans << "\n";
	
}