#include<iostream>
using namespace std;

int main()
{
	string s; cin >> s;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= 'A' && s[i] <= 'Z') s[i] += 32;
		else s[i] -= 32;
	}

	for (int i = 0; i < s.length(); i++) cout << s[i];

	return 0;
}