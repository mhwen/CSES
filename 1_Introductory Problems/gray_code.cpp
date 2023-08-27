#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> arr;
    arr.push_back("");
    for(int i = 0; i < n; i++) {
        int len = arr.size();
        for(int j = len-1; j >= 0; j--) {
            arr.push_back("1"+arr[j]);
        }
        for(int j = 0; j < len; j++) {
            arr[j] = "0"+arr[j];
        }
    }
    for(string s : arr)
        cout << s << "\n";
}