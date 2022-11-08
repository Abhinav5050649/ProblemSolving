#include "bits/stdc++.h"
using namespace std;

const int MOD = 10000007;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(0), cin.tie(0);

	long long n; cin >> n;
	cout << (long long)((long long)(pow(2, n)) % MOD) << endl;

	return 0;
}