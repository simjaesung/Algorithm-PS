#include<iostream>
#include<stack>
using namespace std;

int arr[1000001];
int ans[1000001];

int main()
{
	ios::sync_with_stdio(0); cin.tie(nullptr);
	int n; cin >> n;
	stack<int>s;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		if (s.empty() || arr[s.top()] >= arr[i]) s.push(i);
		//��ų� ��ū���� �ƴ� ���� push
		else if (arr[s.top()] < arr[i]) {
			//��ū���� ��� ��ū���� ����Ǵ� ���� pop
			while (!s.empty() && arr[s.top()] < arr[i]) {
				ans[s.top()] = arr[i];
				s.pop();
			}
			s.push(i);
		}
	}

	//��ū���� ���� ������ ó��
	while (!s.empty()) {
		ans[s.top()] = -1;
		s.pop();
	}

	for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
	return 0;
}