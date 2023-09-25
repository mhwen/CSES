#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> seen;
	int n;
	cin >> n;
	vector<ll> rewards(n);
	vector<pair<int, pair<int, int>>> events(n);
	for(int i = 0; i < n; i++) {
		int a, b;
		ll p;
		cin >> a >> b >> p;
		events.push_back({a, {0, i}});
		events.push_back({b, {1, i}});
		rewards[i] = p;
		
	}
	sort(events.begin(), events.end());
	ll best = 0;
	for(auto e : events) {
		int type = e.second.first;
		int id = e.second.second;
		
		//start
		if(type == 0) {
			rewards[id] += best;
		}
		//end
		else {
			best = max(best, rewards[id]);
		}
	}
	cout << best << "\n";
	
	
}