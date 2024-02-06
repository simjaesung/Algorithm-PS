#include<iostream>
#include<deque>
using namespace std;
int arr[1005];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n, w, l;
	cin >> n >> w >> l;

	for (int i = 0; i < n; i++) cin >> arr[i];

	deque<int>d; 
	int cnt = 0;

	for (int i = 0; i < n; i++) {
		while (1) {
			//�ٸ� ���� Ʈ���� �� �������� �տ��� ��������
			if (d.size() == w) {
				l += d.front();
				d.pop_front();
			}
			//�տ��� ������ ���� Ʈ���� �� �� �ִ� ��� break
			if (l >= arr[i]) break;

			//���� Ʈ���� ���� ���� ��� 0Ű�� �׷� Ʈ���� �÷�
			//���� �о..?
			d.push_back(0);
			cnt++;
		}

		d.push_back(arr[i]);
		l -= arr[i];
		cnt++;
	}

	//������ Ʈ���� �ٸ����� �ǳʴ� �ð� �߰�
	cout << cnt + w;

	return 0;
}