#include<iostream>
#include<deque>
using namespace std;

int main()
{
	int n; cin >> n;
	deque<int>dq;
	  
	while (n--) {
		string s;
		int val;
		cin >> s >> val;

		if (s == "push") dq.push_back(val);
		else if (s == "pop") {
			if (dq.empty()) cout << -1 << '\n';
			else {
				cout << dq.front() << '\n';
				dq.pop_front();
			}
		}
		else if (s == "size") cout << s.size() << '\n';
		else if (s == "empty") {
			if (dq.empty()) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if (s == "front") cout << dq.front() << '\n';
		else if (s == "back") cout << dq.back() << '\n';
	}

	return 0;
}