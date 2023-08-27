#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n-1; i++) {
        cin >> a[i];
    }
    sort(a, a+n-1);
    int ans = n;
    for(int i = 0; i < n-1; i++) {
        if(a[i] != i+1) {
            ans = i+1;
            break;
        }
    }
    cout << ans << "\n";
}