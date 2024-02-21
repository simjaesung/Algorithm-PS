#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

int arr[500005], b[8005];

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
	if(a.first != b.first) return a.first > b.first;
	//빈도수가 같을 경우 작은거부터 출력
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
	
	//산술평균
	if (sum / n < 0 && sum / n > -1) sum *= -1;
	cout << round(sum / n) << '\n';

	//중앙값
	cout << arr[n/2] <<'\n';

	//빈도수
	vector<pair<int,int>>v;
	int mb = 0;
	for (int i = 0; i < 8005;i++) {
		if (b[i] != 0) v.push_back(make_pair(b[i], i - 4000));
		mb = max(mb, b[i]);
		//빈도수와 그 값을 추가
	}

	sort(v.begin(), v.end(), compare);

	//두번째로 작은 값 출력
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