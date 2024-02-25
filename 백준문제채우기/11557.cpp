#include<iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	
	while (t--) {
		int best = -1;
		string bestsh;

		int n; cin >> n;
		while (n--) {
			string s; int sool;
			cin >> s >> sool;
			if (sool > best) {
				bestsh = s;
				best = sool;
			}
		}
		cout << bestsh << '\n';
	}
	
	return 0;
}