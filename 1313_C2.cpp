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
	vector<long long int> l(n + 2);	//0 ~ i ������ ���� (i�� �ִ�)
	vector<long long int> r(n + 2);	//i ~ n ������ ���� (i�� �ִ�)
	stack<int> stk;

	m[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> m[i];
	}
	m[n + 1] = 0;

	//l�� ���ϱ�
	stk.push(0);
	for (int i = 1; i <= n; i++)
	{
		while (m[stk.top()] >= m[i])
			stk.pop();

		l[i] = m[i] * ((long long)i - stk.top()) + l[stk.top()];
		stk.push(i);
	}

	//stack �ʱ�ȭ
	while (!stk.empty())
		stk.pop();
	stk.push(n + 1);
	//r�� ���ϱ�
	for (int i = n; i > 0; i--)
	{
		while (m[stk.top()] >= m[i])
			stk.pop();

		r[i] = m[i] * ((long long)stk.top() - i) + r[stk.top()];
		stk.push(i);
	}

	//l,r�� �̿��ؼ� ���̰� �ִ��� idx�� ���ϱ�
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

	//idx���� ������ ��
	int height = m[idx];
	for (int i = idx + 1; i <= n; i++)
	{
		if (m[i] > height)
			m[i] = height;
		height = m[i];
	}
	//idx���� ���� ��
	height = m[idx];
	for (int i = idx - 1; i > 0; i--)
	{
		if (m[i] > height)
			m[i] = height;
		height = m[i];
	}

	//���
	for (int i = 1; i <= n; i++)
	{
		cout << m[i] << " ";
	}
}