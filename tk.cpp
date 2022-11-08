#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
#define MOD 1e9 + 7;
#define pb push_back;

void solve()
{
    ll n; cin >> n;
    
        // cout << ((((i * i) * ((i * i) - 1)) - 8 - 24 - (16 * (i - 4)) - 16 - ((i - 4) * 24) - ((i - 4) * (i - 4) * 8))/2) << endl;
    for (ll i = 1; i <= n; ++i)
    {
        cout << ((((i * i) * ((i * i) - 1)) - 32 - ((i - 4) * 16) - 16 - ((i - 4) * 24) - ((i - 4) * (i - 4) * 8)) /2) << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    solve();

    return 0;
}