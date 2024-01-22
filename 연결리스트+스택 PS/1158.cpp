#include<iostream>
#include<queue>
using namespace std;

int num[5001] = { 0 };

int main()
{
	int n, k, cnt;
	cin >> n >> k;
	queue<int>Q;
	for (int i = 1; i <= n; i++) Q.push(i);

	cout << '<';
	cnt = 1;
	while (!Q.empty()) {
		if (cnt % k == 0) {
			if (Q.size() == 1)cout << Q.front();
			else cout << Q.front() << ", ";
			Q.pop();
		}
		else {
			Q.push(Q.front());
			Q.pop();
		}
		cnt++;
	}
	
	cout << '>';
	
	
	return 0;
}