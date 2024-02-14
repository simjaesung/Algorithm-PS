#include<iostream>
#include<queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n, k;
	cin >> n >> k;
	queue<int>q;

	for (int i = 1; i <= n; i++) q.push(i);

	int t = 1;

	cout << "<";

	while (q.size() > 1) {
		if (t == k) {
			cout << q.front() << ", ";
			q.pop();
			t = 1;
		}
		else {
			q.push(q.front());
			q.pop();
			t++;
		}
	}
	cout << q.front() << ">";


	return 0;
}