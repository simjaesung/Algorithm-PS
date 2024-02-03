#include<iostream>
using namespace std;

int ans[10];
int n, m;

void go(int k, int start)
{
	if (k == m) {
		for (int i = 0; i < m; i++) cout << ans[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = start; i <= n; i++) {
		ans[k] = i;
		go(k + 1, i);
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	go(0,1);
	return 0;
}