#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
const ll MOD = 1e9 + 7;
#define pb push_back;

void solve()
{
    ll t; cin >> t;
    while (t--)
    {
        ll n, m; cin >> n >> m;

        (n == 1 && m == 1) ? (cout << 0 << endl) : (cout << (min(n, m) + n + m - 2) << endl);
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    solve();

    return 0;
}