#include<iostream>
using namespace std;

int n, s,ans = 0;
int arr[25], check[25];

void go(int select, int index, int m, int sum)
{
	//m���� ����� �� sum�� �հ� �����ϸ� ���� ����
	if (select == m) {
		if (sum == s) ans++;
		return;
	}
	
	if (index > n - 1) return;
	//�ϳ� ���� sum�� �� ���� �߰�
	go(select + 1, index + 1, m, sum + arr[index]);
	//���� �ʰ� ���� �ε����� Ž��
	go(select, index + 1, m, sum);
}


int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> s;
	for (int i = 0; i < n; i++) cin >> arr[i];

	//k���� �� �� ���� s�� �Ǵ� ����� ���� �߰�
	for (int k = 1; k <= n; k++) go(0, 0, k, 0);
	cout << ans;
	return 0;
}