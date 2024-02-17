#include<iostream>
#include<string>
using namespace std;

//¼Ò¹®ÀÚ
int isalpha(char s) {
	if (s >= 'a' && s <= 'z') return 1;
	return 0;
}

int ISALPHA(char s) {
	if (s >= 'A' && s <= 'Z') return 1;
	return 0;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	string s;
	getline(cin, s);
	
	for (auto x : s) {
		if (isalpha(x)) {
			x += 13;
			if (x > 'z' || x < 'a') x -= 26;
		}
		else if (ISALPHA(x)) {
			x += 13;
			if (x > 'Z') x -= 26;
		}
		cout << x;
	}
	return 0;
}