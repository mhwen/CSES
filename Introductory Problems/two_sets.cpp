#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    if(n%4 == 1 || n%4 == 2)
        cout << "NO\n";
    else {
        vector<int> first;
        vector<int> second;
        int start = 1;
        if(n%4==3) {
            first.push_back(1);
            first.push_back(2);
            second.push_back(3);
            start = 4;
        }
        for(int i = start; i <= n; i+=4) {
            first.push_back(i);
            first.push_back(i+3);
            second.push_back(i+1);
            second.push_back(i+2);
        }
        cout << "YES\n";
        cout << first.size() << "\n";
        for(int i : first) {
            cout << i << " ";
        }
        cout << "\n";
        cout << second.size() << "\n";
        for(int i : second) {
            cout << i << " ";
        }
    }
}