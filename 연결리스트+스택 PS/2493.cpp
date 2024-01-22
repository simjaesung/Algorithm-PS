#include<iostream>
#include<stack>

using namespace std;
int t[500001];
int arr[500001] = { 0 };

int main()
{
	ios::sync_with_stdio(0); 
	cin.tie(nullptr); cout.tie(nullptr);

	int n,tall,cnt; cin >> n;

	stack<int>s;
	stack<int>ans; //�������� ���� �� ���� ž�� ����

	for (int i = 1; i <= n; i++) {
		cin >> t[i];
		s.push(i);
	} //�Է� ����� index�� push

	tall = t[s.top()]; //���� ���� ū ������ ž�� ���̸� ����(�����ʺ���)
	ans.push(s.top()); //�ش� ž�� ���� �������� �� ����
	s.pop(); cnt = 1;

	while (!s.empty()) {
		if (t[s.top()] > tall) { //���� ū ž�� ���� �� (�������� �� ���� ž���� Ž���ؾ���)
			while (!ans.empty() && t[s.top()] > t[ans.top()]) {
				arr[ans.top()] = s.top(); //���� ū ž���� ���̰� ���� ž�� ���������� �ش� ž�� ���߰Ե�
				ans.pop();
			}
		}
		tall = t[s.top()]; //���� ū ������ ž ���� ���� �� Ž�� �Ϸ� stack�� ����
		ans.push(s.top()); 
		s.pop();
	}

	for (int i = 1; i <= n; i++) cout << arr[i] << ' ';

	return 0;
}