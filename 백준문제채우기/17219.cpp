#include<iostream>
#include<map>
using namespace std;
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	map<string, string>m;
	int n, s;
	cin >> n >> s;

	while (n--) {
		string site, p; 
		cin >> site >> p;
		m[site] = p;
	}

	while (s--) {
		string f; cin >> f;
		cout << m[f] << '\n';
	}

	return 0;
}