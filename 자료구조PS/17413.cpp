#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string s;
	getline(cin, s);
	s += ' ';

	stack <char> stack;

	int notice = 0; //< > 안 알림 토글

	for (auto x : s) {
		if (notice) {
			if (x == '>') notice = 0;
			cout << x;
		}
		else {
			if (x == '<' || x == ' ') {
				while (!stack.empty()) {
					cout << stack.top();
					stack.pop();
				}
				cout << x;
				if (x == '<') notice = 1;
			}
			else {
				stack.push(x);
			}
		}
	}
}