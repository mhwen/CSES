#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, x;
	cin >> n >> x;
	vector<int> weights(n);
	for(int i = 0; i < n; i++) {
		cin >> weights[i];
	}
	sort(weights.begin(), weights.end());
	int left = 0, right = n-1;
	int count = 0;
	while(left < right) {
		if(weights[left]+weights[right] <= x) {
			left++;
			right--;
		}
		else {
			right--;
		}
		count++;
	}
	if(left == right) {
		count++;
	}
	cout << count << "\n";
}