#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

int arr[500005], b[8005];

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
	if(a.first != b.first) return a.first > b.first;
	//�󵵼��� ���� ��� �����ź��� ���
	return a.second < b.second;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	double sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		b[arr[i] + 4000]++;
		sum += arr[i];
	}
	sort(arr, arr + n);
	
	//������
	if (sum / n < 0 && sum / n > -1) sum *= -1;
	cout << round(sum / n) << '\n';

	//�߾Ӱ�
	cout << arr[n/2] <<'\n';

	//�󵵼�
	vector<pair<int,int>>v;
	int mb = 0;
	for (int i = 0; i < 8005;i++) {
		if (b[i] != 0) v.push_back(make_pair(b[i], i - 4000));
		mb = max(mb, b[i]);
		//�󵵼��� �� ���� �߰�
	}

	sort(v.begin(), v.end(), compare);

	//�ι�°�� ���� �� ���
	if (v.size() > 1) {
		int s = v.size();
		if (v[0].first == v[1].first) 
			cout << v[1].second << '\n';
		else cout << v[0].second << '\n';
	}
	else cout << v[0].second << '\n';
	
	cout << arr[n - 1] - arr[0];
	return 0;
}