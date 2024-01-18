#include<iostream>
#include<algorithm>
using namespace std;
char c[51][51];

int find_longest(int size) {
	int result = 0, val;
	//����
	for (int i = 1; i <= size; i++) {
		for (int k = 1; k <= size; k++) {
			val = 1;
			for (int l = k-1; l >= 1; l--) {
				if (c[i][k] == c[i][l])	val++;
				else break;
			}
			result = max(result, val);
		}
	}
	//����
	for (int j = 1; j <= size; j++) {
		for (int k = 1; k <= size; k++) {
			val = 1;
			for (int l = k - 1; l >= 1; l--) {
				if (c[k][j] == c[l][j])	val++;
				else break;
			}
			result = max(result, val);
		}
	}
	return result;
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);

	int n, ans = 0;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cin >> c[i][j];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			swap(c[i][j], c[i][j + 1]);
			ans = max(ans, find_longest(n));
			swap(c[i][j], c[i][j + 1]);

			if (i < n) {
				swap(c[i][j], c[i + 1][j]);
				ans = max(ans, find_longest(n));
				swap(c[i][j], c[i + 1][j]);
			}
		}
	}
	cout << ans;

	return 0;
}