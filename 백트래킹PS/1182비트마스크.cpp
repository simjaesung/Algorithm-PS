#include<iostream>
using namespace std;

int arr[25];

int main()
{
	int n, s; 
	cin >> n >> s;
	for (int i = 0; i < n; i++) cin >> arr[i];

	int ans = 0;
	//�������� �����Ͽ� 1���� n-1����
	for (int i = 1; i < (1 << n); i++) {
		int tmp = 0;
		//j�� i�� ���տ� ���ϸ� arr[j] ���ϱ�
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) tmp += arr[j];
		}
		//�ش� �κ������� �����ϴٸ� ++
		if (tmp == s) ans++;
	}
	cout << ans;


	return 0;
}