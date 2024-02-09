#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int arr[1005];

bool compare(const pair<int, int>& a, const pair<int, int>& b){
	//�ι�° ���ڰ� ū�� ������
	return a.second > b.second;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n, c;
	cin >> n >> c;

	//���� ������ ����
	vector<int>turn;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];

		//���� ������ ����
		int check = 0;
		for (int s = 0; s < turn.size(); s++) {
			if (arr[i] == turn[s]) {
				check = 1; break;
			}
		}
		if (!check) turn.push_back(arr[i]);
	}
	
	vector<pair<int, int>>v;

	//���� ���� ������ ���� üũ
	for (auto x : turn) {
		int tmp = 0;
		for (int i = 0; i < n; i++) {
			if (x == arr[i]) tmp++;
		}
		v.push_back(make_pair(x, tmp));
	}

	stable_sort(v.begin(), v.end(), compare);

	for (auto x : v) {
		for (int i = 0; i < x.second; i++) cout << x.first << ' ';
	}
	
	return 0;
}