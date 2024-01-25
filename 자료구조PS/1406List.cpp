#include<iostream>
#include<list>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	string s; cin >> s;

	list<char> L;
	for (auto x : s) L.push_back(x);
	auto t = L.end();

	int n; cin >> n;
	while (n--) {
		char cmd;
		cin >> cmd;

		if (cmd == 'L') {
			if (t != L.begin()) t--;
		}
		else if (cmd == 'D') {
			if(t != L.end()) t++;
		}
		else if (cmd == 'B'){
			if (t != L.begin()) {
				t--;
				t = L.erase(t); //그 다음 원소를 반환
			}
		}
		else if (cmd == 'P') {
			char input;
			cin >> input;
			L.insert(t, input);
		}
	}

	for (auto x : L) cout << x;
	
	return 0;
}