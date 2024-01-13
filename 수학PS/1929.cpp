#include <iostream>
#include<vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr), cout.tie(nullptr);

	int m, n;
	cin >> m >> n;

	vector<int>check(n + 1);
	vector<int>prime(n);
	int pcnt = 0;

	for (int i = 2; i <= n; i++) {
		if (!check[i]) {
			prime[pcnt++] = i;
			for (int j = i * 2; j <= n; j += i) {
				check[j] = 1;
			}
		}
	}
	for (auto x : prime) {
		if (x >= m) cout << x << '\n';
	}
	return 0;
}