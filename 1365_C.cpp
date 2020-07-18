#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<pair<int,int>> a(n);
	vector<int> b(n);
	vector<int> diff(n*2,0);
	int max = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++)
	{
		cin >> b[i];
		int k = a[b[i] - 1].second - i;
		if (k < 0)
			k += n;
		diff[k]++;
		if (diff[k] > max)
			max = diff[k];
	}
	cout << max;
}