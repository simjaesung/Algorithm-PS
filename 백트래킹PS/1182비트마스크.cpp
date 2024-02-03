#include<iostream>
using namespace std;

int arr[25];

int main()
{
	int n, s; 
	cin >> n >> s;
	for (int i = 0; i < n; i++) cin >> arr[i];

	int ans = 0;
	//공집합은 제외하여 1부터 n-1까지
	for (int i = 1; i < (1 << n); i++) {
		int tmp = 0;
		//j가 i의 집합에 속하면 arr[j] 더하기
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) tmp += arr[j];
		}
		//해당 부분집합이 동일하다면 ++
		if (tmp == s) ans++;
	}
	cout << ans;


	return 0;
}