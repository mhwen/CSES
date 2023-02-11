#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    long long cost = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(i > 0) {
            cost += max(0, a[i-1]-a[i]);
            a[i] = max(a[i], a[i-1]);
        }
    }
    cout << cost << "\n";
}