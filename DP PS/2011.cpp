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

	//ù�ڸ��� 0�̸� �ؼ� �Ұ�
	if (lock[0] - '0' == 0) {
		cout << 0;
		return 0;
	}
	

	D[0][0] = 1;
	//10�� �ڸ��� �� �� �ִ� �� 1,2 ��
	if (lock[0] - '0' == 1 || lock[0] - '0' == 2) D[0][1] = 1;

	for (int i = 1; i < n; i++) {
		a = lock[i] - '0';
		b = lock[i - 1] - '0';

		D[i][0] = D[i - 1][0] + D[i - 1][1];

		//1�� �ڸ��� 0�� ���
		if (lock[i] - '0' == 0) {
			//���ڸ����� 2, 1�� �ƴϸ� �ؼ� �Ұ�
			if (b != 2 && b != 1) {
				cout << 0;
				return 0;
			}
			D[i][0] = D[i - 1][1];
		}
		//27�̻��� ����� ������ ����
		if (b== 2 && a > 6) D[i][0]--;
		
		D[i][0] %= 1000000;

		//���� 1, 2�� ��츸 10�� �ڸ��� �� �� ����
		if (a == 1 || a== 2) 
			D[i][1] = D[i - 1][0] % 1000000;
	}

	cout << D[n-1][0];

	return 0;

}