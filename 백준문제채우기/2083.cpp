#include<iostream>
using namespace std;
int main()
{
	while (1) {
		string s; int age, h;
		cin >> s >> age >> h;
		if (s == "#" && age == 0 && h == 0) break;
		int check = 1;
		if (age > 17 || h >= 80) check = 0;
		cout << s << ' ';
		if (!check) cout << "Senior\n";
		else cout << "Junior\n";
	}
	return 0;
}