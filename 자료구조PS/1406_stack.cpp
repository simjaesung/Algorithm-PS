#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	string s;
	cin >> s;

	stack<char> left, right;

	for (auto x : s)
		left.push(x);

	int n;
	cin >> n;

	while (n--) {
		char cmd, val;
		cin >> cmd;
		if (cmd == 'P') {
			cin >> val;
			left.push(val);
		}
		else if (cmd == 'L') {
			if (!left.empty()) {
				right.push(left.top());
				left.pop();
			}
		}
		else if (cmd == 'D') {
			if (!right.empty()) {
				left.push(right.top());
				right.pop();
			}
		}
		else if (cmd == 'B') {
			if (!left.empty()) left.pop();
		}
	}

	while (!left.empty()) {
		right.push(left.top());
		left.pop();
	}
	while (!right.empty()) {
		cout << right.top();
		right.pop();
	}

	return 0;
}
