#include<iostream>
using namespace std;
int arr[5][5], b[5][5], c[25];
int ans;

int bingo()
{
	int cnt = 0;
	for (int i = 0; i < 5; i++) {
		int tmp1 = 0, tmp2 = 0;
		for (int j = 0; j < 5; j++) {
			tmp1 += b[i][j];
			tmp2 += b[j][i];
		}
		if (tmp1 == 5) cnt++;
		if (tmp2 == 5) cnt++;
	}

	if (b[4][0] + b[3][1] + b[2][2] + b[1][3] + b[0][4] == 5) cnt++;
	if (b[4][4] + b[3][3] + b[2][2] + b[1][1] + b[0][0] == 5) cnt++;

	return cnt;
}

int check(int val)
{
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (arr[i][j] == val) {
				b[i][j] = 1;
				return bingo();
			}
		}	
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) cin >> arr[i][j];
	}

	for (int i = 0; i < 25; i++) cin >> c[i];

	for (int k = 0; k < 25; k++) {
		if (check(c[k]) >= 3) {
			cout << k + 1;
			return 0;
		}
	}
}