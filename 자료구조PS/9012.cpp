#include <iostream>
#include <string>

using namespace std;


void checkVPS(string vpsstr) {
	int cnt = 0;

	for (int i = 0; i < vpsstr.length(); i++) {
		if (vpsstr[i] == '(') cnt++;
		else cnt--;

		if (cnt < 0) {
			cout << "NO" << '\n';
			return;
		}
	}
	if(cnt == 0) cout << "YES" <<'\n';
	else cout << "NO" << '\n';
}

int main()
{
	int n;
	cin >> n;
	cin.ignore();

	while (n--) {
		string str;
		getline(cin, str);
		checkVPS(str);
	}
	
	return 0;
}