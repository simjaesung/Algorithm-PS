#include<iostream>
#include<deque>
using namespace std;

int main()
{
	int n; cin >> n;

	deque<int>dq;
	for (int i = 1; i <= n; i++) dq.push_back(i);

	int toggle = 1;

	while (dq.size() != 1) {
		if (toggle) {
			dq.pop_front();
			toggle = 0;
		}
		else {
			dq.push_back(dq.front());
			dq.pop_front();
			toggle = 1;
		}
	}

	cout << dq.front();
	return 0;
}