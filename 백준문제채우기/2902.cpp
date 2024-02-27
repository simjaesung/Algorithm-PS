#include<iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	string s; cin >> s;
	cout << s[0];
	for (int i = 1; i < s.length(); i++) {
		if (s[i] == '-') cout << s[i + 1];
	}
	return 0;
}