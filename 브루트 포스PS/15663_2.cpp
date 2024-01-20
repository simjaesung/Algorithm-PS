#include<iostream>
#include<algorithm>
using namespace std;

int n, m, num[10], a[10];
bool c[10];


void go(int index)
{
	if (index == m) {
		for (int i = 0; i < m; i++) cout << a[i] << ' ';
		cout << '\n';
		return;
	}
	int tmp = 0;
	for (int i = 0; i < n; i++){
		if (c[i]) continue;
		if (tmp == num[i]) continue;
		a[index] = num[i];
		tmp = num[i]; //한 자리에 다른 수가 오는 건 제한
		c[i] = true; 
		go(index + 1);
		c[i] = false;
	}
}


int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> num[i];
	sort(num, num + n);
	go(0);
	return 0;
}