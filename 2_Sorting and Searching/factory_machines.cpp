#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

bool possible(ll time, ll needed, vector<ll>& machines) {
	ll count = 0;
	for(ll m : machines) {
		count += time/m;
		if(count >= needed)
			return true;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, t;
	cin >> n >> t;
	vector<ll> machines(n);
	for(int i = 0; i < n; i++) {
		cin >> machines[i];
	}
	ll left = 0, right = 1e18;
	while(left < right) {
		ll mid = (left+right)/2;
		if(!possible(mid, t, machines))
			left = mid+1;
		else
			right = mid;
	}
	cout << left << "\n";
}