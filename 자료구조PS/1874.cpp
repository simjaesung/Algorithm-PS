#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int* arr = new int[n];

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int num = 1, cnt = 0;

	stack<int> stack;
	string s = "";
	
	while (cnt < n) {

		if (stack.empty()){
			stack.push(num++);
			s += '+';
		}
		else {
			if (arr[cnt] > stack.top()) {
				stack.push(num++);
				s += '+';
			}
			else if (arr[cnt] == stack.top()) {
				stack.pop();
				s += '-';
				cnt++;
			}
			else if (arr[cnt] < stack.top()) {
				s = "NO";
				return 0;
			}
		}
	}
	for (auto x :s)
		cout << x << '\n';
	
	return 0;
}