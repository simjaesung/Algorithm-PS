#include<iostream>
#include<deque>
using namespace std;
typedef long long ll;
ll arr[5000001];

int main()
{
	int n, l; cin >> n >> l;
	deque<pair<ll, ll>>dq2; //index / °ª

	for (int i = 0; i < n; i++) cin >> arr[i];
	dq2.push_front(make_pair(0, arr[0]));
	pair<ll,ll> ans = make_pair(0, arr[0]);
	cout << ans.second << ' ';

	for (int i = 1; i < l; i++) {
		if (arr[i] <= dq2.front().second) {
			dq2.push_front(make_pair(i, arr[i]));
			ans = make_pair(i, arr[i]);
		}
		else {
			dq2.push_back(make_pair(i, arr[i]));
		}
		cout << ans.second << ' ';
	}

	for (int i = l; i < n; i++) {
		while (dq2.front().first < i - l + 1) {
			dq2.pop_front();
		}
		ans.first = dq2.front().first;
		ans.second = dq2.front().second;

		if (arr[i] <= dq2.front().second) {
			dq2.push_front(make_pair(i, arr[i]));
			ans = make_pair(i, arr[i]);
		}
		else {
			dq2.push_back(make_pair(i, arr[i]));
		}	
		
		cout << ans.second << ' ';
	}

	return 0;
}