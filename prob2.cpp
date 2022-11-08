#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

void solve()
{
	int lenOfString; cin >> lenOfString;
	string s1, s2;	cin >> s1 >> s2;
	int cnt = 0;

	for (int i = 0; i < lenOfString; ++i)
	{
		if ((s1[i] == s2[i]) || ((s1[i] == 'B' || s1[i] == 'G') && (s2[i] == 'G' || s2[i] == 'B')))
		{
			cnt++;
		}
	}

	if (cnt == lenOfString){
		cout << "YES\n";
		return;
	}
	else
	{
		cout << "NO\n";
		return;
	}
}

int main()
{
	int t; cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}