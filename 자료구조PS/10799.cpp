#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	string s;
	cin >> s;

	int total_stick(0);
	int cnt_stick(0);
	char prev;
	for (auto x : s) {
		if (x == '(') cnt_stick++;
		else {
			cnt_stick--;
			if (prev == '(') total_stick += cnt_stick;
			else total_stick++;
		}
		prev = x;
	}

	cout << total_stick;

	return 0;
}