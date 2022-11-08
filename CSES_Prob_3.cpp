#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

void solve(string inputString);

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(0), cin.tie(0);

	string inputString;  cin >> inputString;

	solve(inputString);

	return 0;
}

void solve(string inputString)
{
	ll len = inputString.length();

	//Logic:- for each character, run a for or while loop which will count repetitions and store max repetitions 
	ll count = INT_MIN;
	for (ll i = 0; i < len; ++i)
	{
		ll temp = 0, j = 0;
		for (j = i; j < len && inputString[i] == inputString[j]; ++j, ++temp);

		i = j - 1;	
		count = max(count, temp);

		if (count == len)	break;
	}

	cout << count << endl;
	return;
}