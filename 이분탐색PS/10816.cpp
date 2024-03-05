#include<iostream>
#include<algorithm>
using namespace std;
int a[500005];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);

	int m; cin >> m;
	while (m--) {
		int val; cin >> val;
		cout << upper_bound(a, a + n, val) - lower_bound(a, a + n, val) << ' ';
	}
	return 0;
}