#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, val;
	cin >> n;

	vector<int> A(n);
	vector<int> NGE(n);

	for (int i = 0; i < n; i++) {
		cin >> val;
		A[i] = val;
	}

	stack<int>s;
	s.push(0);

	for (int i = 1; i < n; i++) {
		while (!s.empty() && A[i] > A[s.top()]) {
			NGE[s.top()] = A[i];
			s.pop();
		}
		s.push(i);
	}
	while (!s.empty()) {
		NGE[s.top()] = -1;
		s.pop();
	}
	for (int i = 0; i < n; i++)
		cout << NGE[i] << ' ';


	return 0;
}