#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int tc;
	cin >> tc;
	while (tc-- != 0)
	{
		int n, m;
		cin >> n >> m;
		vector<vector<int>> arr(n, vector<int>(m));
		vector<bool> r(n);
		vector<bool> c(m);
		int r_cnt = n;
		int c_cnt = m;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> arr[i][j];
				if (arr[i][j] == 1)
				{
					if (!r[i]) 
					{
						r[i] = true;
						r_cnt--;
					}
					if (!c[j]) 
					{
						c[j] = true;
						c_cnt--;
					}
				}
			}
		}

		if (r_cnt > c_cnt)
			r_cnt = c_cnt;

		if (r_cnt % 2 == 0)
			cout << "Vivek";
		else
			cout << "Ashish";

		if (tc != 0)
			cout << "\n";
	}
}

/*
1 2 3 4
0 1 0 0
*/