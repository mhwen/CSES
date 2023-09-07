#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

struct Node {
	Node* next;
	Node* prev;
	int val;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	Node* one = new Node();
	Node* curr = one;
	curr->val = 1;
	for(int i = 2; i <= n; i++) {
		Node* next = new Node();
		next->val = i;
		next->prev = curr;
		curr->next = next;
		curr = next;
	}
	curr->next = one;
	one->prev = curr;
	curr = one;
	for(int i = 0; i < n; i++) {
		Node* next = curr->next;
		cout << next->val << " ";
		curr->next = next->next;
		curr->next->prev = curr;
		curr = curr->next;
	}

}