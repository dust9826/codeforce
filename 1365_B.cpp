#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int tc;
	cin >> tc;
	while (tc-- != 0)
	{
		int n;
		cin >> n;
		vector<int> arr(n);
		bool isTrue = true;
		bool isTrue2 = false;
		int a;
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
			if (i > 0)
				if (arr[i] < arr[i - 1])
					isTrue = false;
		}
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			if (i == 0)
				a = x;
			else if (a != x)
				isTrue2 = true;
		}
		if (isTrue || isTrue2)
			cout << "Yes\n";
		else
			cout << "No\n";
	}
}