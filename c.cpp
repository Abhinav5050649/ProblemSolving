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
        ll n; cin >> n; ll ans = 0;
        string s; cin >> s;
        vll a(n, 1);
        for (ll i = 0; i < n; ++i)
        {
            if (s[i] == '0')
            {
                for (ll j = i + 1; j <= n; j += (i + 1))
                {
                    if (s[j - 1] == '1')    break;
                    else if (a[j - 1] == 0)   continue;

                    a[j - 1] = 0;
                    ans += (i + 1);
                }
            }
        }

        cout << ans << endl;
        a.clear();
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