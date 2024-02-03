#include<iostream>
using namespace std;

int s[10], w[10];
int n, ans = 0, cnt = 0;

void hit(int pick)
{
	if (pick == n + 1) {
		ans = max(ans, cnt);
		return;
	}

	if (s[pick] <= 0 || cnt == n - 1) {
		hit(pick + 1);
		return;
	}

	for (int egg = 1; egg <= n; egg++) {
		//�ٸ� ����� �ľ���
		//�μ��� ����� ġ�� ����
		if (egg == pick || s[egg] <= 0) continue;

		//����� ģ��
		s[egg] -= w[pick];
		s[pick] -= w[egg];
		if (s[egg] <= 0) cnt++;
		if (s[pick] <= 0) cnt++;
		hit(pick + 1);


		//���� ��Ȳ���� �ǵ���
		if (s[egg] <= 0) cnt--;
		if (s[pick] <= 0) cnt--;
		s[egg] += w[pick]; s[pick] += w[egg];
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s[i] >> w[i];
	}

	hit(1);
	cout << ans;
	return 0;
}