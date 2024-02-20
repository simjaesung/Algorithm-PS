#include<iostream>
#include<algorithm>
using namespace std;
//d[i][j] i자리 수,끝자리가 j일때 오르막수일 경우?
long long d[105][10];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	fill(d[1] + 1, d[1] + 10, 1);
	
	for (int i = 2; i <= 100; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0) d[i][0] = d[i - 1][1];
			else if (j == 9) d[i][9] = d[i - 1][8];
			else d[i][j] = (d[i - 1][j - 1] + d[i - 1][j + 1]) % 1000000000;
		}
	}

	int n; cin >> n;
	long long ans = 0;
	for (auto x : d[n]) ans += x % 1000000000;
	cout << ans % 1000000000;
}