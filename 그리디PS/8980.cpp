#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int h[2005][2005]; //���� ���� ����
int arr[2005];
int n, k, m;
bool compare(pair<int, int>a, pair<int, int>b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k >> m;
	vector<pair<int, int>>v;

	while (m--) {
		int s, e, l;
		cin >> s >> e >> l;
		h[s][e] = l;
		v.push_back({ s,e });
	}

	sort(v.begin(), v.end(),compare);

	int ans = 0;

	for (int i = 0; i < v.size(); i++) {
		int a, b, m; //���� �� ����
		a = v[i].first;	b = v[i].second; m = h[a][b];

		int tmp = 0;
		//������ �Ƿ��ִ� ������ ���� ū ��
		for (int i = a; i < b; i++) tmp = max(tmp, arr[i]);
		//m�� ���� �� ������ �ư� �ƴϸ� ���� ĭ��ŭ �Ǿ����
		tmp = min(k - tmp, m);
		//�ƴ� ����
		for (int i = a; i < b; i++) arr[i] += tmp;
		ans += tmp;
	}

	cout << ans;
	return 0;
}