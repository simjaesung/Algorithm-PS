#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n, tmp, idx, ans;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	vector<int>arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr.begin(), arr.end());

	//i�� ���� ���� �Ǻ��ϴ� ��
	for (int i = 0; i < n; i++) {
		int check = 0;
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			tmp = arr[i] - arr[j]; //i�� ������ ������ Ȯ��
			idx = lower_bound(arr.begin(), arr.end(), tmp) - arr.begin();
			while (idx < n && arr[idx] == tmp) {
				if (idx != i && idx != j) {
					check = 1;
					ans++; break;
				}
				idx++;
			}
			if (check) break;
		}
	}
	cout << ans;
	return 0;
}