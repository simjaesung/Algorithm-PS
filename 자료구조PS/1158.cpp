#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main()
{
	int n, k, cnt;
	cin >> n;
	cin >> k;
	queue <int> Q;

	for(int i = 1; i <= n; i++){
		Q.push(i);
	}

	cout << '<';

	while (Q.size() > 1) {
		cnt = k - 1;

		while (cnt--) {
			int live = Q.front();
			Q.push(live);
			Q.pop();
		}
		cout << Q.front() << ", ";
		Q.pop();
	}
	cout << Q.front();
	cout << '>';
}