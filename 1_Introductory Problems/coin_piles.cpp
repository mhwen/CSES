#include <iostream>
using namespace std;

int main() {
    int t;
    int a, b;
    cin >> t;
    while(t--) {
        cin >> a >> b;
        if((a+b)%3 != 0) {
            cout << "NO\n";
        }
        else if(a>2*b || b >2*a) {
            cout << "NO\n";
        }
        else {
            cout << "YES\n";
        }
    }
}