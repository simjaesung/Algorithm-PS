#include<iostream>
using namespace std;
int c[10000005];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m, val;	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> val; c[val]++;
	}

	int ans = 0;
	for (int i = 0; i <= m; i++) {
		if (c[i] && c[m - i]) ans++;
	}
	cout << ans / 2;
	return 0;
}