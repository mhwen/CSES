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
	vector<pair<ll, ll>> tasks(n);
	for(int i = 0; i < n; i++) {
		ll a, d;
		cin >> a >> d;
		tasks[i] = {a, d};
	}
	sort(tasks.begin(), tasks.end());
	ll time = 0;
	ll reward = 0;
	for(int i = 0; i < n; i++) {
		time += tasks[i].first;
		reward += tasks[i].second-time;
	}
	cout << reward << "\n";
}