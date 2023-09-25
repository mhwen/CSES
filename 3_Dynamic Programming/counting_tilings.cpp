#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
constexpr ll MOD = 1e9+7;

bool good(int num, int n) {
	vector<int> digits(n);
	for(int i = 0; i < n; i++) {
		digits[i] = num%3;
		num /= 3;
	}

	for(int i = 0; i < n; i++) {
		if(digits[i] == 0) {
			if(i == n-1 || digits[i+1] != 0)
				return false;
			i++;
		}
	}
	return true;
}

int right(int num, int n) {
	int res = 0;
	for(int i = 0; i < n; i++) {
		if(num%3!=2)
			res += (1<<i);
		num /= 3;
	}
	return res;
}

int left(int num, int n) {
	int res = 0;
	for(int i = 0; i < n; i++) {
		if(num%3!=1)
			res += (1<<i);
		num /= 3;
	}
	return res;
}

/*
	  _
0 -> | |

	  _
1 ->   |

	  _
2 -> |

*/

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	int pow = 1;
	for(int i = 0; i < n; i++)
		pow *= 3;
	
	vector<int> valid;
	for(int i = 0; i < pow; i++) {
		if(good(i, n))
			valid.push_back(i);
	}
	vector<ll> prev(1<<n);
	vector<ll> curr(1<<n);
	prev[(1<<n)-1] = 1;
	vector<int> lefts(valid.size());
	vector<int> rights(valid.size());
	for(int i = 0; i < (int)valid.size(); i++) {
		lefts[i] = left(valid[i], n);
		rights[i] = right(valid[i], n);
	}
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < (int)valid.size(); j++) {
			int next = lefts[j];
			int from = rights[j];
			curr[next] = (curr[next]+prev[from])%MOD;
		}
		
		swap(prev, curr);
		fill(curr.begin(), curr.end(), 0);
	}
	
	cout << prev[(1<<n)-1] << "\n";
}