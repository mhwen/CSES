#include <iostream>
using namespace std;

int bad[8][8];
int dx[8] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy[8] = {1, 0, -1, 1, -1, 1, 0, -1};

bool good(int a) {
    return a >= 0 && a < 8;
}

int recur(int queens) {
    if(queens == 8)
        return 1;
    int count = 0;
    for(int i = 0; i < 8; i++) {
        if(!bad[i][queens]) {
            for(int d = 0; d < 8; d++) {
                int ix = dx[d];
                int jx = dy[d];
                for(int h = 0; h < 8 && good(i+h*ix) && good(queens+h*jx); h++) {
                    bad[i+h*ix][queens+h*jx]++;
                }
            }
            count += recur(queens+1);
            for(int d = 0; d < 8; d++) {
                int ix = dx[d];
                int jx = dy[d];
                for(int h = 0; h < 8 && good(i+h*ix) && good(queens+h*jx); h++) {
                    bad[i+h*ix][queens+h*jx]--;
                }
            }
        }
    }

    return count;
}

int main() {
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            char c;
            cin >> c;
            if(c == '*')
                bad[i][j]++;
        }
    }
    cout << recur(0) << "\n";
    
}