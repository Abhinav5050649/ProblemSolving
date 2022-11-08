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
    ll n, k; cin >> n >> k;
    vll fact(n + 1, 1), r_fact(n + 1);

    for (ll i = 1; i <= n; ++i)
    {
        fact[i] = (fact[i - 1] * i)%mod;
    }

    r_fact[n] = bin_exp(fact[n], mod - 2);

    for (ll i = n - 1; i >= 0; --i)
    {
        r_fact[i] = (((r_fact[i + 1] * (i + 1))%mod));
    }
    
    ll ans = 0;
    for (ll i = 0; i <= min(n, k); ++i)
    {
        ans += (fact[n] * ((r_fact[i] * r_fact[n - i]) % mod))%mod;
        ans %= mod;
    }

    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(0), cin.tie(0);

    solve();

    return 0;
}