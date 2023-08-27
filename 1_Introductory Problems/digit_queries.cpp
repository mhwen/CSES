#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll count_digits(ll a) {
	ll count = 0;
	ll number = 1;
	ll pow = 1;
	while(number*10 <= a) {
		count += 9*pow*number;
		number *= 10;
		pow++;
	}
	ll diff = a-number+1;
	return count+diff*pow;
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int q;
	cin >> q;
	while(q-->0) {
		ll k;
		cin >> k;
		ll left = 1;
		ll right = 1e17;
		while(left < right) {
			ll mid = (left+right)/2;
			if(count_digits(mid) < k) {
				left = mid+1;
			}
			else {
				right = mid;
			}
		}
		// cout << "left " << left << "\n";
		ll diff = k-count_digits(left-1);
		// cout << "diff " << diff << "\n";
		vector<ll> digits;
		while(left > 0) {
			digits.push_back(left%10);
			left /= 10;
		}
		reverse(digits.begin(), digits.end());
		cout << digits[(int)diff-1] << "\n";
		
	}
}