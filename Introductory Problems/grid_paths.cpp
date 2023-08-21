#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
#define SIZE 7

bool vis[SIZE][SIZE];
bool allVis[SIZE][SIZE];
char path[48];
string allowed;
int count = 0;
int dirs[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
char dirC[4] = {'U', 'D', 'L', 'R'};
int degree[SIZE][SIZE];

void fill(int r, int c) {
	allVis[r][c] = true;
	for(int i = 0; i < 4; i++) {
		int rx = dirs[i][0];
		int cx = dirs[i][1];
		if(r+rx < 0 || r+rx >= SIZE || c+cx < 0 || c+cx >= SIZE)
			continue;
		if(!allVis[r+rx][c+cx])
			fill(r+rx, c+cx);
	}
}

void update_degree(int r, int c, int change) {
	for(int i = 0; i < 4; i++) {
		int rx = r+dirs[i][0];
		int cx = c+dirs[i][1];
		if(rx < 0 || rx >= SIZE || cx < 0 || cx >= SIZE)
			continue;
		degree[rx][cx] += change;
	}
}

bool check_blocked(int r, int c) {
	int startR = -1, startC = -1;
	for(int i = 0; i < SIZE; i++) {
		for(int j = 0; j < SIZE; j++) {
			allVis[i][j] = vis[i][j];
			if(!vis[i][j]) {
				startR = i;
				startC = j;
			}
			if(i == 0 && j == 0)
				continue;
			if(vis[i][j])
				continue;
			if(degree[i][j] < 2) {
				return true;
			}
		}
	}
	fill(startR, startC);
	for(int i = 0; i < SIZE; i++) {
		for(int j = 0; j < SIZE; j++) {
			if(!allVis[i][j])
				return true;
		}
	}
	return false;
}

void search(int r, int c, int steps) {
	if(steps >= SIZE*SIZE-1) {
		if(r == 0 && c == 0)
			count++;
		return;
	}
	if(r == 0 && c == 0)
		return;
	
	vis[r][c] = true;
	
	int horz = 0, vert = 0;
	for(int i = 0; i < 4; i++) {
		int rx = r+dirs[i][0];
		int cx = c+dirs[i][1];
		if(rx < 0 || rx >= SIZE || cx < 0 || cx >= SIZE)
			continue;
		if(!vis[rx][cx]) {
			if(i<2)
				vert++;
			else
				horz++;
		}
	}

	if(abs(horz-vert) == 2) {
		vis[r][c] = false;
		return;
	}
	
	// if(steps%4==0 && check_blocked(r, c)) {
		// vis[r][c] = false;
		// return;
	// }

	update_degree(r, c, -1);
	
	int mustTake = 0;
	int takeDir = -1;
	for(int i = 0; i < 4; i++) {
		int rx = r+dirs[i][0];
		int cx = c+dirs[i][1];
		if(rx < 0 || rx >= SIZE || cx < 0 || cx >= SIZE)
			continue;
		if(rx == 0 && cx == 0)
			continue;
		if(!vis[rx][cx] && degree[rx][cx] == 1) {
			mustTake++;
			takeDir = i;
		}
	}
	if(mustTake > 1) {
		update_degree(r, c, 1);
		vis[r][c] = false;
		return;
	}
	else if(mustTake == 1) {
		if(allowed[steps] == '?' || allowed[steps] == dirC[takeDir])
			search(r+dirs[takeDir][0], c+dirs[takeDir][1], steps+1);	
	}
	else {
		for(int i = 0; i < 4; i++) {
			if(allowed[steps] != '?' && allowed[steps] != dirC[i])
				continue;
			int rx = r+dirs[i][0];
			int cx = c+dirs[i][1];
			if(rx < 0 || rx >= SIZE || cx < 0 || cx >= SIZE)
				continue;
			
			if(!vis[rx][cx])
				search(rx, cx, steps+1);	
		}
	}
	
	update_degree(r, c, 1);
	vis[r][c] = false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	for(int r = 0; r < SIZE; r++) {
		for(int c = 0; c < SIZE; c++) {
			update_degree(r, c, 1);
		}
	}
	cin >> allowed;
	search(SIZE-1, 0, 0);
	cout << count << "\n";
}