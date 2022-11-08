#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
const ll mod = 1e9 + 7;
#define pb push_back

void swap(ll &a, ll &b)
{
    a ^= b; b ^= a; a ^= b;
}

ll bin_exp(ll a, ll b)
{
    a %= mod;
    ll res = 1;

    while (b > 0)
    {
        if (b & 1)  res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

ll gcd(ll a, ll b)
{
    if (b == 0) return a;
    else return gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    return ((a * b)/gcd(a, b));
}

void solve()
{
    ll t; cin >> t;
    while (t--)
    {
        ll n = 0, m = 0, cnt1 = 0; cin >> n >> m;
        vector<string> vs;

        for (ll i = 0; i < n; ++i)
        {
            string s; cin >> s; vs.pb(s);
            for (auto it : s)
            {
                if (it == '1')  ++cnt1;
            }
        }

        bool adj = false;
        for (ll i = 0; i < n - 1; ++i)
        {
            for (ll j = 0; j < m - 1; ++j)
            {
                ll dummy = 0;
                dummy += (vs[i][j] == '0');
                dummy += (vs[i + 1][j] == '0');
                dummy += (vs[i][j + 1] == '0');
                dummy += (vs[i + 1][j + 1] == '0');
                
                if (dummy >= 2) adj = true;
            }
        }

        if (adj)    cout << cnt1 << endl;
        else if (cnt1 == n * m) cout << cnt1 - 2 << endl;
        else cout << cnt1 - 1 << endl;

        vs.clear();
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