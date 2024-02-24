#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int arr[100005][2];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<pair<int, int>>v;
	for (int i = 0; i < n; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		v.push_back(make_pair(a * 100 + b, c * 100 + d));
	}
	sort(v.begin(), v.end());

	int end = 0, start = 0; //���� �� ���� �ǰ� ���� ��¥
	int nidx = 0; // ù��°���� ���� ������ idx
	for (int i = 0; i < n; i++) {
		if (v[i].first <= 301) {
			if (end < v[i].second) {
				start = v[i].first;
				end = v[i].second;
			}
			nidx = i;
		}
		else break;
	}

	//3�� 1�Ͽ� ���� ���ٸ� 
	if (end <= 301) {
		cout << 0;
		return 0;
	}

	int ans = 1; // 1���� ���� ��

	while (end < 1201) {
		int maxend = end; //���� �� ���� ���� ���� �ǰ� ���� �ʲ� ���� ��
		for (int i = nidx + 1; i < n; i++) {
			if (v[i].first <= end && v[i].second > maxend)
				maxend = v[i].second;
		}
		if (maxend == end) {
			cout << 0;
			return 0;
		}
		ans++;
		end = maxend;
	}
	
	cout << ans;
	return 0;
}
