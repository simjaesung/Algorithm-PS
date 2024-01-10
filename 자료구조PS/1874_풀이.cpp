#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	stack<int> stack;
	string ans = "";

	int n;
	cin >> n;

	int m = 0;

	while (n--) {
		int x;
		cin >> x;
		if (x > m) {
			while (x > m) {
				stack.push(++m);
				ans += "+";
			}
			stack.pop();
			ans += '-';
		}
		else {
			bool find = false;
			if (!stack.empty()) {
				if(stack.top() == x){
					find = true;
					stack.pop();
					ans += '-';
				}
			}
			if (!find) {
				cout << "NO";
				return 0;
			}
		}		
	}

	for (auto x : ans)
		cout << x << '\n';


	
	
	
	return 0;
}