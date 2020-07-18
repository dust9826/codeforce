#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int tc;
	cin >> tc;
	while (tc-- != 0)
	{
		int n;
		cin >> n;
		int a = 0, b = 0;
		while (true)
		{
			if (n % 2 == 0)
			{
				a++;
				n /= 2;
			}
			if (n % 3 == 0)
			{
				b++;
				n /= 3;
			}
			if (n % 2 != 0 && n % 3 != 0)
			{
				break;
			}
		}
		if (a > b || n != 1)
		{
			cout << "-1\n";
		}
		else if (a == b)
		{
			cout << a << "\n";
		}
		else
		{
			cout << b * 2 - a << "\n";
		}
	}
}