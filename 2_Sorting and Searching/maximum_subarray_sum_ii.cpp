#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, a, b;
	cin >> n >> a >> b;
	a--;
	ll best = -1e18;
	multiset<ll> seen;
	ll sum = 0;
	vector<ll> sums(n+1);
	for(int i = 0; i < n; i++) {
		if(i >= a)
			seen.insert(sums[i-a]);
		if(i >= b)
			seen.erase(seen.find(sums[i-b]));
			
		ll num;
		cin >> num;
		sum += num;
		sums[i+1] = sum;
		if(!seen.empty())
			best = max(best, sum-(*seen.begin()));

	}
	cout << best << "\n";
}