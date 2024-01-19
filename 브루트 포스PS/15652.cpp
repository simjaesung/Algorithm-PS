#include<iostream>
using namespace std;

int ans[10];

void go(int index, int start, int n, int m) 
{
	if (index == m) {
		for (int i = 0; i < m; i++)
			cout << ans[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = start; i <= n; i++) {
		ans[index] = i;
		go(index + 1, i, n, m);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cout.tie(nullptr);
	int m, n; cin >> n >> m;
	go(0, 1, n, m);
	return 0;
}