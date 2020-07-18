#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int tc;
	cin >> tc;
	while(tc--!=0)
	{
		int n, x;
		cin >> n >> x;
		int a;
		int odd = 0, pair = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> a;
			if (a % 2 == 0)
				pair++;
			else
				odd++;
		}
		if (odd == 0)
			cout << "NO\n";
		else
		{
			if (x <= pair)
				cout << "YES\n";
			else if (n == x)
			{
				if (odd % 2 == 0)
					cout << "NO\n";
				else
					cout << "YES\n";
			}
			else if (n == x + 1)
			{
				if (pair == 0 && x % 2 == 0)
					cout << "NO\n";
				else
					cout << "YES\n";
			}
			else
			{
				if (pair == 0 && x % 2 == 0)
					cout << "NO\n";
				else
					cout << "YES\n";
			}
		}
	}
}