#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
#define pb push_back
const ll mod = 1e9 + 7;
typedef vector<ll> vll;
typedef vector<int> vii;

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
        if (b & 1)  res = res * a % mod;
        a = a * a % mod;
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
        unordered_map<ll, ll> ump;
        ll n = 0, cnt = 0, pd = 0, d = 0, ans = 0;
        cin >> n;

        for (ll i = 0; i < n; ++i)
        {
            cin >> d;
            if (pd == d) continue;

            if (ump.find(d) == ump.end())   ++cnt;
            ump[d]++;

            if (pd > d) ans = cnt - 1;
            if (ump[d] > 1)   ans = cnt;

            pd = d;
        }

        cout << ans << endl;
        ump.clear();
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