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
        ll n; cin >> n;
        vll arr(n, 0);
        for (ll i = 0; i < n; ++i)  cin >> arr[i];

        vll check;
        for (ll i = 1; i <= n; ++i) check.pb(i);

        if (n == 1) cout << -1 << endl;
        else
        {
            for (ll i = 0; i < n - 1; ++i)
            {
                if (arr[i] == check[i]) swap(check[i], check[i + 1]);
            }

            if (arr[n - 1] == check[n - 1]) swap(check[n - 1], check[n - 2]);

            for (ll i = 0; i < n; ++i)
            {
                cout << check[i] << " ";
            }
            cout << endl;
            check.clear(), arr.clear();
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