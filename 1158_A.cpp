//https://codeforces.com/problemset/problem/1158/A
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	vector<int> b(m);
	long long int sum=0;
	int maxA_1 = 0, maxA_2 = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		sum += a[i];
		if (a[i] > maxA_1)
		{
			maxA_2 = maxA_1;
			maxA_1 = a[i];
		}
		else if (a[i] > maxA_2)
		{
			maxA_2 = a[i];
		}
	}
	sum *= m;
	int min_B = 1000000000;
	long long int sum_B = 0;
	for (int i = 0; i < m; i++)
	{
		cin >> b[i];
		sum_B += b[i];
		if (min_B > b[i])
			min_B = b[i];
	}

	if (maxA_1 > min_B)
	{
		cout << "-1";
		return 0;
	}
	else if (maxA_1 == min_B)
	{
		sum_B -= (long long)maxA_1 * m;
		cout << sum + sum_B;
	}
	else
	{
		sum_B -= (long long)maxA_1 * m;
		sum_B += (long long)maxA_1 - maxA_2;
		cout << sum + sum_B;
	}
}