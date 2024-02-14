#include<iostream>
using namespace std;

int arr[105][105];


int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;

	while (n--) {
		int a, b;
		cin >> a >> b;

		for (int i = b; i < b + 10; i++) {
			for (int j = a; j < a + 10; j++) arr[i][j] = 1;
		}
	}

	int ans = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (arr[i][j] == 1) ans++;
		}
	}
	cout << ans;

	return 0;
}