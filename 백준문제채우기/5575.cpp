#include<iostream>
using namespace std;
int main()
{
	for (int i = 0; i < 3; i++) {
		int h1, m1, s1, h2, m2, s2;
		cin >> h1 >> m1 >> s1 >> h2 >> m2 >> s2;
		int ans1, ans2, ans3;
		ans1 = s2 - s1;
		ans2 = m2 - m1;
		ans3 = h2 - h1;
		if (ans1 < 0) {
			ans2--;
			ans1 += 60;
		}

		if (ans2 < 0) {
			ans3--;
			ans2 += 60;
		}
		cout << ans3 << ' ' << ans2 << ' ' << ans1 << '\n';
	}
	return 0;
}