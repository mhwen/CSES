#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> movies(n);
	multiset<int> people;
	for(int i = 0; i < k; i++)
		people.insert(0);
	
	for(int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		movies[i] = {b, a};
	}
	sort(movies.begin(), movies.end());
	int count = 0;
	for(auto m : movies) {
		int start = m.second;
		int end = m.first;
		auto it = people.upper_bound(start);
		if(it != people.begin()) {
			count++;
			it--;
			people.erase(it);
			people.insert(end);
		}
	}
	cout << count << "\n";
}