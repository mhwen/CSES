#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k;
	cin >> n >> k;
	int root = (int)sqrt(n)+1;
	vector<vector<int>> buckets(root);
	for(int i = 1; i <= n; i++) {
		int bucket = (i-1)/root;
		buckets[bucket].push_back(i);
	}
	int currIndex = 0;
	int bucketIndex = 0;
	for(int i = 0; i < n; i++) {
		int toRemove = k%(n-i);
		while(toRemove > 0 && currIndex < (int)buckets[bucketIndex].size()) {
			toRemove--;
			currIndex++;
		}
		if(currIndex == (int)buckets[bucketIndex].size()) {
			currIndex = 0;
			bucketIndex = (bucketIndex+1)%root;
		}
		while(toRemove >= 0 && toRemove >= (int)buckets[bucketIndex].size()) {
			toRemove -= (int)buckets[bucketIndex].size();
			bucketIndex = (bucketIndex+1)%root;
		}
		while(toRemove > 0 && currIndex < (int)buckets[bucketIndex].size()) {
			currIndex++;
			toRemove--;
		}
		cout << buckets[bucketIndex][currIndex] << " ";
		buckets[bucketIndex].erase(buckets[bucketIndex].begin()+currIndex);
		if(i == n-1)
			break;
		while(currIndex >= (int)buckets[bucketIndex].size()) {
			currIndex = 0;
			bucketIndex = (bucketIndex+1)%root;
		}
	}
}