#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int arr[55][15];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 9; j++) cin >> arr[i][j];
	}
	//Ÿ�� ����
	int b[] = { 1,2,3,4,5,6,7,8 };
	int ans = 0;

	do {
		int score = 0;
		int turn = 0; int idx = 0;

		for (int ing = 1; ing <= n; ing++) {
			int out = 0; //�ƿ��� �̴׺���
			int cnt = 0; //Ȩ������ ���ڵ�

			vector<int>j; //����

			while (out < 3) {
				turn %= 9; idx %= 8;
				int t, tmp; //Ÿ�� ������ ���� ��Ÿ�� �ƴ���

				if (turn == 3) t = 1; //4��Ÿ��
				else t = b[idx++] + 1;
				turn++;

				tmp = arr[ing][t];
				
				if (tmp == 0) {
					out++; continue;
				}

				//Ÿ��ģ ���� ����
				j.push_back(tmp);

				//�������ִ� Ÿ�ڵ� ����
				for (int i = cnt; i < j.size()-1; i++) j[i] += tmp;

				//Ȩ�� ���� Ÿ�� ǥ��
				for (int i = cnt; i < j.size(); i++) {
					if (j[i] > 3) cnt++;
				}
			}
			score += cnt;

		}
		ans = max(score, ans);

	} while (next_permutation(b, b + 8));

	cout << ans;
	return 0;
}