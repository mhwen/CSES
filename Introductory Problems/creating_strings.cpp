#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

void recur(int curr, vector<int>& permutation, string s, set<string>& found) {
    if(curr == 0) {
        string a = "";
        for(int& i : permutation) {
            a += s[i];
        }
        found.insert(a);
        return;
    }
    for(int i = 0; i < (int)s.length(); i++) {
        if(count(permutation.begin(), permutation.end(), i) == 0) {
            permutation.push_back(i);
            recur(curr-1, permutation, s, found);
            permutation.pop_back();
        }
    }
}

int main() {
    string s;
    cin >> s;
    vector<int> permutation;
    set<string> found;
    recur(s.length(), permutation, s, found);
    cout << found.size() << "\n";
    for(const string& f : found) {
        cout << f << "\n";
    }
}