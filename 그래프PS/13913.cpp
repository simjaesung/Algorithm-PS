#include<iostream>
#include<queue>
using namespace std;

int arr[100001], c1[100001], c2[100001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;

	queue<int>q1;
	q1.push(n);
	c1[n] = 1;
	while (!q1.empty()) {
		int cx = q1.front(); q1.pop();
		if (cx == m)break;
		for (int nx : {cx - 1, cx + 1, cx * 2}) {
			if (nx < 0 || nx > 100000) continue;
			if (c1[nx] == 0) {
				c1[nx] = c1[cx] + 1;
				q1.push(nx);
			}

		}
	}

	queue<int>q2;
	q2.push(m);
	c2[m] = 1;
	while (!q2.empty()) {
		int cx = q2.front(); q2.pop();
		if (cx == n)break;
		if (cx % 2 == 1) {
			for (int nx : {cx - 1, cx + 1}) {
				if (nx < 0 || nx > 100000) continue;
				if (c2[nx] == 0) {
					c2[nx] = c2[cx] + 1;
					q2.push(nx);
				}
			}
		}
		else {
			for (int nx : {cx - 1, cx + 1, cx / 2}) {
				if (nx < 0 || nx > 100000) continue;
				if (c2[nx] == 0) {
					c2[nx] = c2[cx] + 1;
					q2.push(nx);
				}
			}
		}
		
	}

	int ans = c1[m];
	cout << ans - 1 <<'\n';

	for (int i = 1; i <= ans; i++) {
		for (int j = 0; j <= 100000; j++) {
			if (c1[j] == i && c2[j] == ans + 1 - i) {
				cout << j << ' ';
				break;
			}
		}
		
	}
	return 0;
}
