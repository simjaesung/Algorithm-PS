#include<iostream>
#include<string>
using namespace std;
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	string s; cin >> s;

	int ans = 0;
	bool minus = false; //minus ���
	string tmp; //���� ���ڿ� ����
	for (int i = 0; i < s.length(); i++) {
		if (s[i] != '-' && s[i] != '+') tmp += s[i];
		else {
			int val = stoi(tmp);
			tmp.clear();

			//�տ� -�� ����������,
			if (minus) ans -= val;
			else ans += val;

			if (s[i] == '-') minus = true;
		}
	}

	if (minus) ans -= stoi(tmp);
	else ans += stoi(tmp);

	cout << ans;

	return 0;
}