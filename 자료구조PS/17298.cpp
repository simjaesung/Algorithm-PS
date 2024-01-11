#include <iostream>
#include <deque>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, val;
	cin >> n;

	deque<int>D;
	stack<int>s;

	while (n--) {
		cin >> val;
		D.push_back(val);
	}

	n = D.size();
	int first(1);

	while (n--) {
		val = D.front();
		first = 1;
		D.pop_front();
		int size = D.size();
		while (size--) {
			int right = D.front();
			D.pop_front();
			s.push(right);

			if (right > val) {
				if (first) cout << right << " ";
				first = 0;
				break;
			}			
		}
		if(first) cout << -1 << ' ';

		while (!s.empty()) {
			int top = s.top();
			s.pop();
			D.push_front(top);
		}
	}
}