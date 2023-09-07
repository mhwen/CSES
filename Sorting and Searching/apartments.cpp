#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> people(n);
	vector<int> apartments(m);
	for(int i = 0; i < n; i++) {
		cin >> people[i];
	}
	for(int i = 0; i < m; i++) {
		cin >> apartments[i];
	}
	sort(people.begin(), people.end());
	sort(apartments.begin(), apartments.end());
	int p = 0, a = 0;
	int ans = 0;
	while(p < n && a < m) {
		if(abs(people[p]-apartments[a]) <= k) {
			ans++;
			p++;
			a++;
		}
		else if(people[p] < apartments[a])
			p++;
		else
			a++;
	}
	cout << ans << "\n";
}