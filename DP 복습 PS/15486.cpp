#include<iostream>
using namespace std;
int t[1500005], p[1500005], d[1500005];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> t[i] >> p[i];

	for (int i = 1; i <= n; i++) {
		d[i] = max(d[i], d[i - 1]);

		if (i + t[i] - 1 <= n) {
			d[i + t[i]] = max(d[i + t[i]], d[i] + p[i]);
		}
	}
	cout << max(d[n], d[n + 1]);

	return 0;
}