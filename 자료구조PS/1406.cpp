#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	string s;
	cin >> s;

	stack<char> stack;

	for (auto x : s)
		stack.push(x);
	
	s.erase();

	int n;
	cin >> n;

	while (n--) {
		char cmd, val;
		cin >> cmd;
		if (cmd == 'P') {
			cin >> val;
			stack.push(val);
		}
		else if (cmd == 'L') {
			if (!stack.empty()) {
				s += stack.top();
				stack.pop();
			}
		}
		else if (cmd == 'D') {
			int slen(s.length());
			if(slen > 0){
				stack.push(s[slen-1]);
				s.erase(slen - 1);
			}
		}
		else if (cmd == 'B') {
			if (!stack.empty())	stack.pop();
		}
	}

	while (!stack.empty()) {
		s += stack.top();
		stack.pop();
	}

	for (int i = s.length() - 1; i >= 0; i--)
		cout << s[i];
	
	return 0;
}
