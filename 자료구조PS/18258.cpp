#include<iostream>
#include<deque>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int n; cin >> n;
	deque<int>dq;

	while (n--) {
		string s;
		cin >> s;

		if (s == "push") {
			int val; cin >> val;
			dq.push_back(val);
		}
		else if (s == "pop") {
			if (dq.empty()) cout << -1 << '\n';
			else {
				cout << dq.front() << '\n';
				dq.pop_front();
			}
		}
		else if (s == "size") cout << dq.size() << '\n';
		else if (s == "empty") {
			if (dq.empty()) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if (s == "front") {
			if (!dq.empty()) cout << dq.front() << '\n';
			else cout << -1 <<'\n';
		}
		else if (s == "back") {
			if (!dq.empty()) cout << dq.back() << '\n';
			else cout << -1 << '\n';
		}
			
	}

	return 0;
}