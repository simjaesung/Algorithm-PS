#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
int n, m;
int ans = INT_MAX;
vector<pair<int, int>>h; //�� ��ġ
vector<pair<int, int>>ch; //ġŲ �� ��ġ

int c[15], chic[15];

void go(int select,int start, int maxch)
{
	//�������� ���� ������ 0 ~ M�� ��
	if (select ==  maxch) {
		//��ü ���� ġŲ �Ÿ� ����
		int d = 0;
		for (int home = 0; home < h.size(); home++) {
			int tmp = INT_MAX;
			
			//���õ� ġŲ �� �� �� ���� ġŲ �Ÿ� ���ϱ�
			for (int i = 0; i < select; i++) {
				int hx = h[home].first;
				int hy = h[home].second;
				int cx = ch[chic[i]].first;
				int cy = ch[chic[i]].second;
				tmp = min(abs(hx-cx) + abs(hy-cy),tmp);
			}

			d += tmp;
		}

		ans = min(d, ans);
		return;
	}

	for (int i = start; i < ch.size(); i++) {
		if (c[i]) continue;
		chic[select] = i; c[i] = 1;
		go(select + 1, i + 1, maxch);
		c[i] = 0;
	}

}



int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int val; cin >> val;
			if (val == 2) ch.push_back(make_pair(i, j));
			else if (val == 1) h.push_back(make_pair(i, j));
			else continue;
		}
	}

	for (int i = 1; i <= m; i++) go(0,0,i);

	cout << ans;

	return 0;
}