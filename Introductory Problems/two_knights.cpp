#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long count = 0;
    for(long long i = 1; i <= n; i++) {
        long long squares = i*i;
        //6+12+(i-4)*8-2
        if(i >= 3)
            count += 8*i-16;
        cout << squares*(squares-1)/2 - count << "\n";
    }
}