#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<pair<int, pair<int, int>>> customers(n);
	for(int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		customers[i] = {a, {b, i}};
	}
	sort(customers.begin(), customers.end());
	vector<int> ans(n);
	priority_queue<int, vector<int>, greater<int>> rooms;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> times;
	int used = 0;
	for(int i = 0; i < n; i++) {
		int start = customers[i].first;
		int end = customers[i].second.first;
		int id = customers[i].second.second;
		while(!times.empty() && times.top().first < start) {
			rooms.push(times.top().second);
			times.pop();
		}
		if(rooms.empty())
			rooms.push(++used);
		ans[id] = rooms.top();
		rooms.pop();
		times.push({end, ans[id]});
	}
	cout << used << "\n";
	for(int i : ans)
		cout << i << " ";
	cout << "\n";
}