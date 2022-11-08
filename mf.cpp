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
    ll n; cin >> n;
    vector<pair<ll, ll>> vpll;

    for (ll i = 0; i < n; ++i)
    {
        ll n1, n2; cin >> n1 >> n2;
        vpll.pb({n2, n1});
    }
    sort(vpll.begin(), vpll.end());

    ll cnt = 0, cur_end = 0;
    
    for (auto it: vpll)
    {
        if (it.second >= cur_end)   cur_end = it.first, ++cnt;
    }

    cout << cnt << endl;
    vpll.clear();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(0), cin.tie(0);

    solve();

    return 0;
}