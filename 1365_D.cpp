#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int main()
{
	int tc;
	cin >> tc;
	while (tc--!=0)
	{
		int n, m;
		cin >> n >> m;
		vector<string> arr(n);
		queue<pair<int, int>> bad;
		int good = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
			for (int j = 0; j < m; j++)
			{
				if (arr[i][j] == 'B')
					bad.push({ i,j });
				else if (arr[i][j] == 'G')
					good++;
			}
		}
		pair<int, int> a[4] = { {0,1},{0,-1},{1,0},{-1,0} };
		while (!bad.empty())
		{
			for (int i = 0; i < 4; i++)
			{
				int x = bad.front().first + a[i].first;
				int y = bad.front().second + a[i].second;
				if ((x >= 0) && (x < n) && (y >= 0) && (y < m))
					arr[x][y] = '#';
			}
			bad.pop();
		}
		queue<pair<int,int>> bfs;
		bfs.push({ n - 1, m - 1 });
		if (arr[n - 1][m - 1] == '#')
		{
			if (good == 0)
				cout << "Yes\n";
			else
				cout << "No\n";
			continue;
		}
		arr[n - 1][m - 1] = '#';
		while (!bfs.empty())
		{
			for (int i = 0; i < 4; i++)
			{
				int x = bfs.front().first + a[i].first;
				int y = bfs.front().second + a[i].second;
				if ((x >= 0) && (x < n) && (y >= 0) && (y < m))
				{
					if (arr[x][y] == '.')
					{
						bfs.push({ x,y });
						arr[x][y] = '#';
					}
					if (arr[x][y] == 'G')
					{
						good--;
						bfs.push({ x,y });
						arr[x][y] = '#';
					}
				}
			}
			bfs.pop();
		}
		if (good == 0)
			cout << "Yes\n";
		else
			cout << "No\n";
	}
}