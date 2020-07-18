//https://codeforces.com/problemset/problem/1313/C2
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

typedef pair<int, int> pii;

int main()
{
	int n;
	cin >> n;
	vector<long long int> m(n + 2);
	vector<long long int> l(n + 2);	//0 ~ i 까지의 넓이 (i가 최대)
	vector<long long int> r(n + 2);	//i ~ n 까지의 넓이 (i가 최대)
	stack<int> stk;

	m[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> m[i];
	}
	m[n + 1] = 0;

	//l값 구하기
	stk.push(0);
	for (int i = 1; i <= n; i++)
	{
		while (m[stk.top()] >= m[i])
			stk.pop();

		l[i] = m[i] * ((long long)i - stk.top()) + l[stk.top()];
		stk.push(i);
	}

	//stack 초기화
	while (!stk.empty())
		stk.pop();
	stk.push(n + 1);
	//r값 구하기
	for (int i = n; i > 0; i--)
	{
		while (m[stk.top()] >= m[i])
			stk.pop();

		r[i] = m[i] * ((long long)stk.top() - i) + r[stk.top()];
		stk.push(i);
	}

	//l,r을 이용해서 넓이가 최대인 idx값 구하기
	int idx = 0;
	long long int max = 0;
	for (int i = 1; i <= n; i++)
	{
		long long int value = l[i] + r[i] - m[i];
		if (value > max)
		{
			max = value;
			idx = i;
		}
	}

	//idx기준 오른쪽 값
	int height = m[idx];
	for (int i = idx + 1; i <= n; i++)
	{
		if (m[i] > height)
			m[i] = height;
		height = m[i];
	}
	//idx기준 왼쪽 값
	height = m[idx];
	for (int i = idx - 1; i > 0; i--)
	{
		if (m[i] > height)
			m[i] = height;
		height = m[i];
	}

	//출력
	for (int i = 1; i <= n; i++)
	{
		cout << m[i] << " ";
	}
}