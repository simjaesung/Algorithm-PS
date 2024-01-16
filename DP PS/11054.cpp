#include<iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);

	int num[1001], d[1001];

	int n, max_val = 1, max_idx = 1, ans = 1;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> num[i];
		if (num[i] >= max_val) {
			max_val = num[i];
			max_idx = i;
		}	
	}

	for (int i = 1; i <= max_idx; i++) {
		d[i] = 1;
		for (int j = i - 1; j >= 1; j--) {
			if (num[i] > num[j]) d[i] = max(d[i], d[j] + 1);
		}
		ans = max(ans, d[i]);
	}

	for (int i = max_idx + 1; i <= n; i++) {
		d[i] = 1;
		for (int j = i - 1; j >= max_idx; j--) {
			if (num[j] > num[i]) d[i] = max(d[i], d[j] + 1);
		}
		ans = max(ans, d[i]);
	}

	cout << ans;
	
	return 0;
}