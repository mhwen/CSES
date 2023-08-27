#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long count = 0;
    int curr = 5;
    while(curr <= n) {
        count += n/curr;
        curr *= 5;
    }
    cout << count;
}