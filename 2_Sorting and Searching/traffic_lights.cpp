#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int x, n;
	cin >> x >> n;
	set<int> street;
	vector<int> lights(n);
	for(int i = 0; i < n; i++) {
		cin >> lights[i];
		street.insert(lights[i]);
	}
	street.insert(0);
	street.insert(x);
	int best = 0;
	int prev = 0;
	for(int i : street) {
		best = max(best, i-prev);
		prev = i;
	}
	vector<int> ans;
	ans.push_back(best);
	reverse(lights.begin(), lights.end());
	for(int i = 0; i < n-1; i++) {
		street.erase(lights[i]);
		auto it = street.upper_bound(lights[i]);
		best = max(best, *it - *(--it));
		ans.push_back(best);
	}
	reverse(ans.begin(), ans.end());
	for(int i : ans)
		cout << i << " ";
	cout << "\n";
	
}