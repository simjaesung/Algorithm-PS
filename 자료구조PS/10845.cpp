#include <iostream>
#include <string>

using namespace std;

typedef struct queue {

	int list[10000];

	int start;
	int end;

	queue() {
		start = 0;
		end = 0;
	}

	void push(int val)
	{
		list[end++] = val;
	}

	int pop() 
	{
		if (empty()) return - 1;

		int result = list[start];
		list[start++] = 0;

		return result;
	}

	int size()
	{
		return end - start;
	}

	int empty()
	{
		if (end == start) return 1;
		else return 0;
	}

	int front()
	{
		if (empty()) return -1;

		return list[start];
	}

	int back()
	{
		if (empty()) return -1;

		return list[end-1];
	}

} queue;



int main() 
{
	int n, val;
	cin >> n;

	queue Q;
	string cmd;
	while (n--)
	{
		cin >> cmd;

		if (cmd == "push") {
			cin >> val;
			Q.push(val);
		}
		else if (cmd == "pop") {
			cout << Q.pop() << '\n';
		}
		else if (cmd == "size") {
			cout << Q.size() << '\n';
		}
		else if (cmd == "empty") {
			cout << Q.empty() << '\n';
		}
		else if (cmd == "front"){
			cout << Q.front() << '\n';
		}
		else if (cmd == "back") {
			cout << Q.back() << '\n';
		}
	}

}