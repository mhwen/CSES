#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string s;
    cin >> s;
    vector<int> freq(26);
    for(char c : s) {
        freq[c-'A']++;
    }
    int odd = 0;
    for(int i : freq) {
        if(i&1)
            odd++;
    }
    if(odd > 1)
        cout << "NO SOLUTION\n";
    else {
        vector<char> ans(s.length());
        int index = 0;
        for(int i = 0; i < (int)freq.size(); i++) {
            for(int j = 0; j < freq[i]/2; j++) {
                ans[index++] = (char)i+'A';
            }
        }
        for(int i = 0; i < (int)freq.size(); i++) {
            if(freq[i]&1)
                ans[index++] = i+'A';
        }
        for(int i = freq.size()-1; i >= 0; i--) {
            for(int j = 0; j < freq[i]/2; j++) {
                ans[index++] = i+'A';
            }
        }
        for(char c : ans)
            cout << c;
    }
}