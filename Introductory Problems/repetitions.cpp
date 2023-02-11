#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    char prev = 0;
    int len = 0;
    int best = 0;
    for(char& c : s) {
        if(prev != c) {
            len = 1;
            prev = c;
        }
        else {
            len++;
        }
        best = max(best, len);
    }
    cout << best << "\n";
}