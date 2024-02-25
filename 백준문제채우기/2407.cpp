#include<iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	unsigned long long ans = 1;
	int n, m; cin >> n >> m;

	m = min(m, n - m);
	for (int i = 0; i < m; i++) {
		ans *= n;
		n--;
	}

	int t = m;
	for (int i = 0; i < m; i++) {
		ans /= t;
		t--;
	}
	
	cout << ans;
	
	return 0;
}