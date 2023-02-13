#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int nums[n];
    long long sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
        sum += nums[i];
    }
    long long best = sum;
    for(int i = 0; i < (1<<n); i++) {
        long long half = 0;
        for(int j = 0; j < n; j++) {
            if(i&(1<<j)) {
                half += nums[j];
            }
        }
        best = min(best, abs(sum-half-half));
    }
    cout << best << "\n";
}