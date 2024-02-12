#include<iostream>
#include<algorithm>
using namespace std;

int n, l;
int arr[105][105], c[105][105];

bool inrange(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < n;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cin >> arr[i][j];
	}


	int ans = 0;
	//��Ȯ��
	for (int i = 0; i < n; i++) {
		int cango = 1;
		for (int j = 1; j < n; j++) {
			//���� ���̰� 2 �̻��� ���
			if (abs(arr[i][j] - arr[i][j - 1]) > 1) {
				cango = 0;
				break;
			}

			//���� ���̰� ���� ���
			if (arr[i][j] == arr[i][j - 1]) continue;

			//�������� �� Ŭ ���
			if (arr[i][j] > arr[i][j - 1]) {
				int val = l; int check = 0;
				while (val > 0) {
					//������ ��� ���
					//�̹� ���θ� ��ġ�� ���
					//���� ���̰� 1�� �ƴ� ���
					if (!inrange(i, j - val) || c[i][j - val] == 1
						|| arr[i][j] - arr[i][j - val] != 1) {
						check = 1; break;
					}
					val--;
				}

				if (check) {
					cango = 0; break;
				}
				else {
					int val = l;
					while (val > 0) {
						c[i][j - val] = 1;
						val--;
					}
				}

			}
			//������ �� Ŭ ���
			//-1ĭ�� ���ؾ���
			else {
				int val = l; int check = 0;
				while (val > 0) {
					if (!inrange(i, j - 1 + val) || c[i][j - 1 + val] == 1 
						|| arr[i][j - 1] - arr[i][j  - 1 + val] != 1) {
						check = 1; break;
					}
					val--;

				}
				if (check) {
					cango = 0; break;
				}
				else {
					int val = l;
					while (val > 0) {
						c[i][j - 1 + val] = 1;
						val--;
					}
				}

			}
		}
		if (cango) ans++;
	}



	for (int i = 0; i < n; i++) fill(c[i], c[i] + n, 0);



	//�� Ȯ��
	for (int j = 0; j < n; j++) {
		int cango = 1;
		for (int i = 1; i < n; i++) {
			//���� ���̰� 2 �̻��� ���
			if (abs(arr[i][j] - arr[i-1][j]) > 1) {
				cango = 0;
				break;
			}

			//���� ���̰� ���� ���
			if (arr[i][j] == arr[i-1][j]) continue;

			//�Ʒ��� �� Ŭ ���
			if (arr[i][j] > arr[i-1][j]) {
				int val = l; int check = 0;
				while (val > 0) {
					//������ ��� ���
					//�̹� ���θ� ��ġ�� ���
					//���� ���̰� 1�� �ƴ� ���
					if (!inrange(i-val, j) || c[i - val][j] == 1 
						|| arr[i][j] - arr[i - val][j] != 1) {
						check = 1; break;
					}
					val--;
				}
				if (check) {
					cango = 0; break;
				}
				else {
					int val = l;
					while (val > 0) {
						c[i - val][j] = 1;
						val--;
					}
				}

			}
			//���� �� Ŭ ���
			//-1ĭ�� ���ؾ���
			else {
				int val = l; int check = 0;
				while (val > 0) {
					if (!inrange(i+val - 1, j) || c[i + val - 1][j] == 1
						|| arr[i - 1][j] - arr[i + val - 1][j] != 1) {
						check = 1; break;
					}
					val--;
				}
				if (check) {
					cango = 0; break;
				}
				else {
					int val = l;
					while (val > 0) {
						c[i + val - 1][j] = 1;
						val--;
					}
				}
			}
		}
		if (cango) ans++;
	}


	cout << ans;
	
	
	return 0;
}