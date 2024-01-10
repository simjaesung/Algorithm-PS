#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	stack<char>s;

	int n;
	cin >> n;
	cin.ignore();

	while (n--) {
		string string;

		getline(cin, string);
		string += '\n';

		for (int i = 0; i < string.length(); i++) {
			
			if (string[i] == ' ' || string[i] == '\n') {
				while (s.size() != 0) {
					cout << s.top();
					s.pop();
				}
				cout << string[i];
			}
			else s.push(string[i]);
		}
	}
}