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
	ll largest = 0;
	ll sum = 0;
	for(int i = 0; i < n; i++) {
		ll t;
		cin >> t;
		sum += t;
		largest = max(largest , t);
	}
	cout << max(largest*2, sum) << "\n";
}