#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	multiset<int> tickets;
	for(int i = 0; i < n; i++) {
		int a;
		cin >> a;
		tickets.insert(a);
	}
	for(int i = 0; i < m; i++) {
		int a;
		cin >> a;
		auto it = tickets.upper_bound(a);
		if(tickets.empty() || it == tickets.begin())
			cout << -1 << "\n";
		else {
			cout << *(--it) << "\n";
			tickets.erase(it);
		}

	}
}