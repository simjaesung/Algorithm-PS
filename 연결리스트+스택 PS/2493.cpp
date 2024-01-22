#include<iostream>
#include<stack>

using namespace std;
int t[500001];
int arr[500001] = { 0 };

int main()
{
	ios::sync_with_stdio(0); 
	cin.tie(nullptr); cout.tie(nullptr);

	int n,tall,cnt; cin >> n;

	stack<int>s;
	stack<int>ans; //레이저를 아직 못 맞춘 탑들 저장

	for (int i = 1; i <= n; i++) {
		cin >> t[i];
		s.push(i);
	} //입력 순대로 index를 push

	tall = t[s.top()]; //현재 가장 큰 레이저 탑의 높이를 저장(오른쪽부터)
	ans.push(s.top()); //해당 탑은 아직 레이저를 못 맞춤
	s.pop(); cnt = 1;

	while (!s.empty()) {
		if (t[s.top()] > tall) { //가장 큰 탑을 만날 시 (레이저를 못 맞춘 탑들을 탐색해야함)
			while (!ans.empty() && t[s.top()] > t[ans.top()]) {
				arr[ans.top()] = s.top(); //가장 큰 탑보다 높이가 낮은 탑의 레이저들은 해당 탑을 맞추게됨
				ans.pop();
			}
		}
		tall = t[s.top()]; //가장 큰 레이저 탑 높이 저장 후 탐색 완료 stack에 저장
		ans.push(s.top()); 
		s.pop();
	}

	for (int i = 1; i <= n; i++) cout << arr[i] << ' ';

	return 0;
}