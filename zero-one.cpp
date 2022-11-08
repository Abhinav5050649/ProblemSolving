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
        string a, b; 
        ll n, x, y, d = 0;
        cin >> n >> x >> y >> a >> b;

        for (ll i = 0; i < n; ++i)
        {
            a[i] ^= b[i];
            d += a[i];
        }

        if (d % 2)
        {
            cout << -1 << endl;
            continue;
        }

        if (d == 2)
        {
            ll l, r;
            for (l = 0; !a[l];) l++;
            
            for (r = n - 1; !a[r]; )    r--;

            if (l + 1  == r)    cout << min(x, 2 * y)   << endl;
            else    cout << min(1*x, y) << endl;
        }
        else{
            cout << d/2 * y << endl;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(0), cin.tie(0);

    solve();

    return 0;
}