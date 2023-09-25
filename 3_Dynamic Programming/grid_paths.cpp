#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
constexpr int MOD = 1e9+7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<vector<int>> grid(n+1, vector<int>(n+1));
	for(int r = 1; r <= n; r++) {
		string s;
		cin >> s;
		for(int c = 1; c <= n; c++) {
			if(s[c-1] == '.') {
				grid[r][c] = (grid[r-1][c]+grid[r][c-1])%MOD;\
				if(r == 1 && c == 1)
					grid[r][c] = 1;
			}
		}
	}
	cout << grid[n][n] << "\n";
}