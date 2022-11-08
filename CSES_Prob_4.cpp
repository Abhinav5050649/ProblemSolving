#include "bits/stdc++.h"
using namespace std;

//Solve in the morning
typedef long long ll;

void solve();

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(0), cin.tie(0);

	solve();

	return 0;
}

void solve()
{
	ll n; cin >> n;
	vector<ll> arr;

	for (ll i = 0; i < n; ++i)
	{
		ll num; cin>> num;	
		arr.push_back(num);
	}

	ll cnt = 0;
	for (ll i = 1; i < n; ++i)
	{
		if (arr[i] < arr[i - 1])
		{
			cnt += abs(arr[i- 1] - arr[i]);
			arr[i] += abs(arr[i - 1] - arr[i]);
		}
	}

	cout << cnt << endl;
	arr.clear();
	return;
}