#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	set<int> nums;
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		nums.insert(x);
	}
	cout << nums.size();
}