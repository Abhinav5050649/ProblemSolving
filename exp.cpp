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

ll bin_pow(ll a, ll b)
{
    a %= mod;
    ll res = 1;

    while (b > 0)
    {
        if (b & 1)  res = res *a % mod;
        a = a * a % mod;
        b >>= 1;
    }

    return res;
}

void solve()
{
    ll n; cin >> n;
    while (n--)
    {
        ll a, b; cin >> a >> b;
        if (a == 0 && b == 0)   cout << 1 << '\n';
        else    cout << bin_pow(a, b) << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(0), cin.tie(0);

    solve();

    return 0;
}