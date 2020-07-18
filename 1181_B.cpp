//https://codeforces.com/problemset/problem/1181/B
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

string Func(string s1, string s2)
{
	int r1 = s1.length();
	int r2 = s2.length();
	int r3 = r1 > r2 ? r1 : r2;
	string answer;
	answer.resize(++r3);
	int i = 0;
	int a;
	int b;
	int c;
	while (true)
	{
		if (r3 < 0)
			break;

		if (r1 < 0)
			a = 0;
		else
			a = s1[r1--] - '0';

		if (r2 < 0)
			b = 0;
		else
			b = s2[r2--] - '0';

		c = a + b + i;

		if (c >= 10)
		{
			c -= 10;
			i = 1;
		}
		else
			i = 0;

		answer[r3--] = c + '0';
	}
	if (answer[0] == '0')
		answer = answer.substr(1);
	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	string s;
	string sub1;
	string sub2;
	cin >> n;
	cin >> s;

	int front = 0;
	int mid = s.length() / 2;

	if (s[mid] == '0')
	{
		int mid1 = mid;
		int mid2 = mid;
		string s1;
		string s2;

		while (true)
		{
			if (s[mid1] != '0')
				break;
			mid1--;
		}
		sub1 = s.substr(0, mid1);
		sub2 = s.substr(mid1);
		s1 = Func(sub1, sub2);

		while (true)
		{
			if (s[mid2] != '0')
				break;
			mid2++;
		}
		sub1 = s.substr(0, mid2);
		sub2 = s.substr(mid2);
		s2 = Func(sub1, sub2);

		if (s1.length() > s2.length())
			s1 = s2;
		else if (s1.length() == s2.length())
		{
			if (s1 > s2)
				s1 = s2;
		}

		cout << s1;
	}
	else if(s.length() % 2 == 1)
	{
		sub1 = s.substr(0, mid);
		sub2 = s.substr(mid);
		string s1 = Func(sub1, sub2);
		mid++;
		if (s[mid] != '0')
		{
			sub1 = s.substr(0, mid);
			sub2 = s.substr(mid);
			string s2 = Func(sub1, sub2);
			if (s1.length() > s2.length())
				s1 = s2;
			else if (s1.length() == s2.length())
			{
				if (s1 > s2)
					s1 = s2;
			}
		}
		cout << s1;
	}
	else
	{
		sub1 = s.substr(0, mid);
		sub2 = s.substr(mid);
		string s1 = Func(sub1, sub2);
		cout << s1;
	}
}