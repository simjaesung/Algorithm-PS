#include<iostream>

using namespace std;
int D[100001][3] = { 0 };

int main()
{	
	int n,ans = 0;
	cin >> n;

	D[1][0] = 1, D[1][1] = 1, D[1][2] = 1;

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			if (j == 0) D[i][0] = (D[i - 1][0] + D[i - 1][1] + D[i - 1][2]) % 9901;
			else if (j == 1) D[i][1] = (D[i - 1][0] + D[i - 1][2]) % 9901;
			else D[i][2] = (D[i - 1][0] + D[i - 1][1]) % 9901;
		}
	}

	for (int j = 0; j < 3; j++) ans += D[n][j];

	cout << ans % 9901;
	
	return 0;
}