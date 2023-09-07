#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, q;
	cin >> n >> q;
	vector<vector<int>> grid(n+1, vector<int>(n+1));
	for(int r = 1; r <= n; r++) {
		for(int c = 1; c <= n; c++) {
			grid[r][c] = grid[r-1][c]+grid[r][c-1]-grid[r-1][c-1];
			char cc;
			cin >> cc;
			if(cc == '*')
				grid[r][c]++;
		}
	}
	while(q-->0) {
		int y1, x1, y2, x2;
		cin >> y1 >> x1 >> y2 >> x2;
		cout << grid[y2][x2]-grid[y1-1][x2]-grid[y2][x1-1]+grid[y1-1][x1-1] << "\n";
	}
}