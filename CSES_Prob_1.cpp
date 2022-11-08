#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

void solve(ll n)
{
	ll temp = n;
	cout << temp <<  " ";
	while (temp != 1)
	{
		if (temp % 2 == 0){
			temp /= 2;
			cout << temp << " ";
		}
		else
		{
			temp = (3 * temp) + 1;
			cout << temp << " ";
		}
	}
	cout << "\n";
}


int main()
{
	ll n; cin >> n;
	solve(n);
	return 0;
}