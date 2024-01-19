#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int n; cin >> n;
	int M, N, x, y, ans;

	while (n--) {
		cin >> M >> N >> x >> y;
		ans = -1;
		x -= 1; y -= 1;
		for (int i = x % M; i <= M*N; i += M) {
			if (i % N == y % N) {
				ans = i + 1;
				break;
			}
		}
		cout << ans<< '\n';
	}
	return 0;
}