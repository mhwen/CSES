#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	vector<int> nums(n);
	vector<int> positions(n+1);
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		nums[i] = x;
		positions[x] = i;
	}
	int rounds = 1;
	for(int i = 2; i <= n; i++) {
		if(positions[i] < positions[i-1])
			rounds++;
	}
	for(int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		int num1 = nums[a];
		int num2 = nums[b];
		
		int prevInversions = 0;
		if(num1 > 1 && positions[num1] < positions[num1-1])
			prevInversions++;
		if(num1 < n && positions[num1+1] < positions[num1])
			prevInversions++;
		if(num2 > 1 && positions[num2] < positions[num2-1])
			prevInversions++;
		if(num2 < n && positions[num2+1] < positions[num2])
			prevInversions++;
		
		int smaller = min(num1, num2);
		int larger = max(num1, num2);
		if(abs(num1-num2)==1 && positions[larger] < positions[smaller])
			prevInversions--;
		
		nums[a] = num2;
		nums[b] = num1;
		positions[num1] = b;
		positions[num2] = a;
		int newInversions = 0;
		
		if(num1 > 1 && positions[num1] < positions[num1-1])
			newInversions++;
		if(num1 < n && positions[num1+1] < positions[num1])
			newInversions++;
		if(num2 > 1 && positions[num2] < positions[num2-1])
			newInversions++;
		if(num2 < n && positions[num2+1] < positions[num2])
			newInversions++;
		
		if(abs(num1-num2)==1 && positions[larger] < positions[smaller])
			newInversions--;
			
		rounds += newInversions-prevInversions;
		cout << rounds << "\n";

	}
}