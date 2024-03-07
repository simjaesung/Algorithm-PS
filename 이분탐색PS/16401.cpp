#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int m, n, val;
vector<int>snack;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		cin >> val; snack.push_back(val);
	}

	sort(snack.begin(), snack.end());

	int s = 1, e = snack[n - 1], ans = 0;
	while (s <= e) {
		int mid = (s + e) / 2;
		int cnt = 0;
		for (int i = 0; i < n; i++) cnt += snack[i] / mid;

		if (cnt < m) e = mid - 1;
		else {
			s = mid + 1;
			ans = mid;
		}
	}
	cout << ans;
	return 0;
}
