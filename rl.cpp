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
        ll n, x, y; cin >> n >> x >> y;

        if ((x && y) || (x + y == 0))   {cout << "-1" << endl; continue;}
        
        x = max(x, y);

        if ((n - 1) % x != 0)   {cout << "-1" << endl; continue;}

        ll p = 1, avail = 1, c = 0;

        for (ll i = 0; i < n - 1; ++i)
        {
            ++c;
            if (c <= x)
            {
                cout << p << " ";
            }
            else
            {
                c = 1;
                p = (i + 2);
                cout << p << " ";
            }
        }
        cout << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(0), cin.tie(0);

    solve();

    return 0;
}