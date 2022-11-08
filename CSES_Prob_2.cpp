#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

void solve(ll n)
{
	vector<ll> arr;
	for (ll i = 0; i < n - 1; ++i)
	{
		ll num; cin >> num;
		arr.push_back(num);
	}

	sort(arr.begin(), arr.end());

	for (ll i= 0; i < n - 1; ++i)
	{
		if (arr[i] != (i + 1))
		{
			cout << (i + 1) << "\n";
			arr.clear();
			return;
		}
		else
		{
			continue;
		}
	}

	cout << (n) << "\n";
	return;
}

int main()
{
	ll n; cin >> n;
	solve(n);
	return 0;
}