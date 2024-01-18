#include<iostream>
using namespace std;

int D[5000][2] = { 0 };

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);

	string lock;
	cin >> lock;
	size_t n = lock.length();

	int a, b;

	//첫자리가 0이면 해석 불가
	if (lock[0] - '0' == 0) {
		cout << 0;
		return 0;
	}
	

	D[0][0] = 1;
	//10의 자리로 올 수 있는 건 1,2 뿐
	if (lock[0] - '0' == 1 || lock[0] - '0' == 2) D[0][1] = 1;

	for (int i = 1; i < n; i++) {
		a = lock[i] - '0';
		b = lock[i - 1] - '0';

		D[i][0] = D[i - 1][0] + D[i - 1][1];

		//1의 자리가 0일 경우
		if (lock[i] - '0' == 0) {
			//앞자리수가 2, 1이 아니면 해석 불가
			if (b != 2 && b != 1) {
				cout << 0;
				return 0;
			}
			D[i][0] = D[i - 1][1];
		}
		//27이상은 경우의 수에서 제외
		if (b== 2 && a > 6) D[i][0]--;
		
		D[i][0] %= 1000000;

		//수가 1, 2인 경우만 10의 자리가 될 수 있음
		if (a == 1 || a== 2) 
			D[i][1] = D[i - 1][0] % 1000000;
	}

	cout << D[n-1][0];

	return 0;

}