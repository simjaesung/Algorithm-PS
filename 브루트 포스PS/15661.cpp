#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;

int arr[21][21], c[11];
int n;
int ans = INT_MAX;

void go1(int select, int idx)
{
	if (select > 0) {
		
		vector<int>v;
		int t1 = 0, t2 = 0;

		for (int i = 1; i <= n; i++) {
			int check = 1;
			for (int j = 0; j < select; j++) {
				if (i == c[j]) check = 0;
			}
			if (check) v.push_back(i);
		}

		for (int i = 0; i < select; i++) {
			for (int j = 0; j < select; j++) {
				t1 += arr[c[i]][c[j]];
			}
		}

		for (int i = 0; i < n - select; i++) {
			for (int j = 0; j < n - select; j++) {
				t2 += arr[v[i]][v[j]];
			}
		}

		ans = min(ans, abs(t1 - t2));
		if (select > n / 2) return;
	}

	if (idx > n) return;

	c[select] = idx;
	go1(select + 1, idx + 1);
	c[select] = 0;
	go1(select, idx + 1);
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) cin >> arr[i][j];
	}
	go1(0, 1);
	cout << ans;

	return 0;
}