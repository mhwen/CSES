#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> positions(n+1);
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		positions[x] = i;
	}
	int rounds = 1;
	for(int i = 2; i <= n; i++) {
		if(positions[i] < positions[i-1])
			rounds++;
	}
	cout << rounds << "\n";
}