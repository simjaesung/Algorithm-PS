#include<iostream>
#include<algorithm>
#include<vector>
#include<limits.h>
using namespace std;
vector<pair<int, int>>v;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n,t; cin >> n;
	t = n;

	int minx = INT_MAX, maxy = INT_MIN;

	while (t--) {
		int a, b;
		cin >> a >> b;
		minx = min(minx, a);
		maxy = max(maxy, b);
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end());

	int len = maxy - minx; //�ִ� ����
	int en = v[0].second; //�ʱ� �� ��
	
	int tmp = 0; //������ �κ��� �� ���� 
	for (int i = 1; i < n; i++) {
		if (v[i].first <= en) {
			if (v[i].second > en) en = v[i].second;
		}
		else {
			tmp += v[i].first - en;
			en = v[i].second;
		}
	}
	cout << len - tmp;
	
	return 0;
}