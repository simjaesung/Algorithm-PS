#include<iostream>
#include<stack>
#include<vector>
using namespace std;
long long build[80001];

int main()
{
	ios::sync_with_stdio(0); cin.tie(nullptr);
	stack<pair<long long, long long>> s;

	long long n, cnt; cin >> n;
	long long ans = 0;

	for (long long i = 0; i < n; i++) cin >> build[i]; //�������� stack push
	for (long long i = n - 1; i >= 0; i--) {
		cnt = 0; //���̴� ���� ����
		//������ ������ ���� ��� �� �տ� ������ ���� ���
		if (s.empty() || s.top().first >= build[i]) s.push(make_pair(build[i], cnt));
		//���̴� ������ ������ ���Ƹ� �� pop, �̋� pop�Ǵ� �������� ������ ������ ���� �� ������ �� ���̴� ����(����)�� �ݿ�
		else if (build[i] > s.top().first) {
			while (!s.empty() && build[i] > s.top().first) {
				cnt++; cnt += s.top().second;
				ans += s.top().second;
				s.pop();
			}
			s.push(make_pair(build[i], cnt));
		}
	}
	//���ÿ� �����ִ� ������ ������ �ݿ�
	while (!s.empty()) {
		ans += s.top().second;
		s.pop();
	}

	cout << ans;
	return 0;
}