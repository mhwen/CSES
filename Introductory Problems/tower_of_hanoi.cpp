#include <iostream>
#include <vector>
using namespace std;


void solve(int size, int from, int to, int other, vector<pair<int, int>>& moves) {
    if(size == 0)
        return;
    solve(size-1, from, other, to, moves);
    moves.push_back(make_pair(from, to));
    solve(size-1, other, to, from, moves);
}   

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> moves;
    solve(n, 1, 3, 2, moves);
    cout << moves.size() << "\n";
    for(pair<int, int>& i : moves) {
        cout << i.first << " " << i.second << "\n";
    }
}