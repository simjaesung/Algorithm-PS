#include<iostream>
#include<limits.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m, ans = INT_MAX;
	cin >> n >> m;

	int s = 1000, l = 1000;
	while (m--) {
		int a, b;
		cin >> a >> b;
		s = min(s, a);
		l = min(l, b);
	}

	//6�� ��Ű���� ��� ���
	ans = min(ans, s * (n / 6 + 1));
	//�����θ� ��°��
	ans = min(ans, l * n);
	//6�� ��Ű���� ������ ȥ���ؼ� ��� ���
	ans = min(ans, (s * (n / 6)) + (l * (n % 6)));

	cout << ans << '\n';
	return 0;
}