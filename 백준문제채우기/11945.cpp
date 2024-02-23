#include<iostream>
using namespace std;
char arr[15][15];
int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < m; j++) arr[i][j] = s[j];
	}

	for (int i = 0; i < n; i++) {
		for (int j = m-1; j >=0; j--) cout << arr[i][j];
		cout << '\n';
	}
	
	return 0;
}