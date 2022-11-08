#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

void solve()
{
	int lenOfString; cin >> lenOfString;
	string s1, s2;
	cin >> s1;
	s2 = "Timur";
	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());
	if (s1 == s2)	cout << "YES\n";
	else	cout << "NO\n";
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