#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int main()
{
	string s; cin >> s;
	vector<string>v;

	for (int i = 0; i < s.length(); i++) v.push_back(s.substr(i));
	sort(v.begin(), v.end());

	for (auto x : v) cout << x << '\n';
	return 0;
}