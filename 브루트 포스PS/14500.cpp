#include<iostream>
using namespace std;
int arr[501][501];

int main()
{
	int N, M, ans = 0;
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (i <= N - 3) { //세로 4개
				ans = max(ans, arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 3][j]);
			}
		}
		for (int j = 1; j <= M; j++) {
			if (j <= M - 3) {//가로 4개
				ans = max(ans, arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i][j + 3]);
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M-2; j++) {
			if (i == 1) { //가로 3개
				ans = max(ans, arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j]);
				ans = max(ans, arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j + 1]);
				ans = max(ans, arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j + 2]);
			}
			else if (i == N) {
				ans = max(ans, arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i - 1][j]);
				ans = max(ans, arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i - 1][j + 1]);
				ans = max(ans, arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i - 1][j + 2]);
			}
			else {
				ans = max(ans, arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i - 1][j]);
				ans = max(ans, arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i - 1][j + 1]);
				ans = max(ans, arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i - 1][j - 1]);
				ans = max(ans, arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j]);
				ans = max(ans, arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j + 1]);
				ans = max(ans, arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j - 1]);
			}
		}
		for (int j = 1; j <= M; j++) {
			if (i <= N - 1) { //세로3개
				if (j == 1) {
					ans = max(ans, arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i][j + 1]);
					ans = max(ans, arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 1][j + 1]);
					ans = max(ans, arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 2][j + 1]);
				}
				else if (j == M) {
					ans = max(ans, arr[i][j] + arr[i - 1][j] + arr[i - 2][j] + arr[i][j - 1]);
					ans = max(ans, arr[i][j] + arr[i - 1][j] + arr[i - 2][j] + arr[i - 1][j - 1]);
					ans = max(ans, arr[i][j] + arr[i - 1][j] + arr[i - 2][j] + arr[i - 2][j - 1]);
				}
				else {
					ans = max(ans, arr[i][j] + arr[i + 1][j] + arr[i - 1][j] + arr[i][j + 1]);
					ans = max(ans, arr[i][j] + arr[i + 1][j] + arr[i - 1][j] + arr[i + 1][j + 1]);
					ans = max(ans, arr[i][j] + arr[i + 1][j] + arr[i - 1][j] + arr[i - 1][j + 1]);
					ans = max(ans, arr[i][j] + arr[i - 1][j] + arr[i + 1][j] + arr[i][j - 1]);
					ans = max(ans, arr[i][j] + arr[i - 1][j] + arr[i + 1][j] + arr[i - 1][j - 1]);
					ans = max(ans, arr[i][j] + arr[i - 1][j] + arr[i + 1][j] + arr[i + 1][j - 1]);
				}
			}
		}
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M - 1; j++) { //가로 2개
				if (j == 1) {
					ans = max(ans, arr[i][j] + arr[i][j + 1] + arr[i + 1][j] + arr[i + 1][j + 1]);
					ans = max(ans, arr[i][j] + arr[i][j + 1] + arr[i + 1][j + 1] + arr[i + 1][j + 2]);
					cout << ans << '\n';
				}
				else if (j == M - 1) {
					ans = max(ans, arr[i][j] + arr[i][j + 1] + arr[i + 1][j] + arr[i + 1][j + 1]);
					ans = max(ans, arr[i][j] + arr[i][j + 1] + arr[i + 1][j] + arr[i + 1][j + 1]);
				}
				else {
					ans = max(ans, arr[i][j] + arr[i-1][j] + arr[i][j + 1] + arr[i + 1][j + 1]);
					ans = max(ans, arr[i][j] + arr[i + 1][j] + arr[i][j + 1] + arr[i - 1][j + 1]);
					ans = max(ans, arr[i][j] + arr[i][j + 1] + arr[i - 1][j] + arr[i - 1][j + 1]);
					ans = max(ans, arr[i][j] + arr[i][j + 1] + arr[i + 1][j] + arr[i + 1][j + 1]);
					
				}
			}
			for (int j = 1; j <= M; j++) { //세로 2개
				if (i <= N - 1) {
					if (j == 1) {
						ans = max(ans, arr[i][j] + arr[i + 1][j] + arr[i + 1][j + 1] + arr[i + 2][j + 1]);
						ans = max(ans, arr[i][j] + arr[i][j + 1] + arr[i + 1][j] + arr[i + 1][j + 1]);
					}
					else if (j == M){
						ans = max(ans, arr[i][j] + arr[i][j + 1] + arr[i + 1][j] + arr[i + 1][j + 1]);
						ans = max(ans, arr[i][j] + arr[i+1][j] + arr[i][j + 1] + arr[i - 1][j + 1]);
					}
					else {
						ans = max(ans, arr[i][j] + arr[i][j - 1] + arr[i - 1][j - 1] + arr[i + 1][j]);
						ans = max(ans, arr[i][j] + arr[i + 1][j] + arr[i][j + 1] + arr[i - 1][j]);
					}
				}
			}
		}

	}
	
	cout << ans <<' ';
	


	return 0;
}