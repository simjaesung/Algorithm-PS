#include<iostream>
using namespace std;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);

	int n, ans=0;
	cin >> n;

	int num[1001], d[1001];
	for (int i = 1; i <= n; i++) cin >> num[i];

	for (int i = 1; i <= n; i++) {
		d[i] = 1;
		for (int j = i - 1; j >= 1; j--) {
			if (num[i] < num[j]) {
				d[i] = max(d[j] + 1, d[i]);
			}
		}
		ans = max(ans, d[i]);
	}

	cout << ans;

	return 0;
}