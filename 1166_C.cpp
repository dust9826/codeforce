//https://codeforces.com/problemset/problem/1166/C
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
long long int answer;
vector<long long int> arr;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	answer = 0;
	arr.resize(n);
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		if (a < 0)
			arr[i] = -a;
		else
			arr[i] = a;
	} 

	sort(arr.begin(), arr.end());
	arr.push_back(2000000001);
	for (int i = 0; i < n - 1; i++)
	{
		long long int a = arr[i] * 2;
		answer += upper_bound(arr.begin(), arr.end(), a) - arr.begin() - i - 1;
	}
	cout << answer;
}