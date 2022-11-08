#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
#define MOD 1e9 + 7;
#define pb push_back;

void towerOfHanoi(int n, int a, int b, int c)
{
    if (n > 0)
    {
        towerOfHanoi(n - 1, a, c, b);
        cout << a << " " << b << endl;
        towerOfHanoi(n - 1, c, b, a);
    }
}

void solve()
{
    ll n; cin >> n;

    cout << (1 << n) - 1 << endl;

    towerOfHanoi(n, 1, 3, 2);
}


int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    solve();

    return 0;
}