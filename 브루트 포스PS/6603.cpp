#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int arr[14];
int c[14];
void go(int index, int select,int n)
{
	if (select == 6) {
		for (int i = 0; i < 6; i++) {
			cout << arr[c[i]] << ' ';
		}
		cout << '\n';
		return;
	}
	//if (index > n) return;

	c[select] = index;
	go(index + 1, select + 1, n);
	c[select] = 0;
	go(index + 1, select, n);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr), cout.tie(nullptr);

	while (1) {
		int n; cin >> n;
		if (n == 0) break;
		for (int i = 1; i <= n; i++) cin >> arr[i];

		go(1, 0, n);
		cout << '\n';
	}

	return 0;
}
