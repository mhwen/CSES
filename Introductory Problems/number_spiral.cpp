#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int x, y;
        cin >> y >> x;
        long long outer = max(x,y);
        long long n = outer*outer;
        if(x == y) {
            n = n-y+1;
        }
        else if(x < y) {
            if(y&1) {
                n = n-2*y+x+1;
            }
            else {
                n = n-x+1;
            }
        }
        else {
            if(x&1) {
                n = n-y+1;
            }
            else {
                n = n-2*x+y+1;
            }
        }
        cout << n << "\n";
    }
}