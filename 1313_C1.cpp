//https://codeforces.com/problemset/problem/1313/C1
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> m(n);
	vector<int> answer(n);
	long long int sum = 0;

	for (int i = 0; i < n; i++)
	{
		cin >> m[i];
	}

	for (int i = 0; i < n; i++)
	{
		vector<int> temp(n);
		long long int tempSum = 0;

		temp[i] = m[i];
		tempSum += temp[i];

		int index = i - 1;
		int max = m[i];

		while (index >= 0)
		{
			if (max > m[index])
			{
				max = m[index];
			}
			temp[index--] = max;
			tempSum += max;
		}

		index = i + 1;
		max = m[i];

		while (index < n)
		{
			if (max > m[index])
			{
				max = m[index];
			}
			temp[index++] = max;
			tempSum += max;
		}

		if (tempSum > sum)
		{
			sum = tempSum;
			answer = temp;
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << answer[i] << " ";
	}
}