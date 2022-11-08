#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
const ll mod = 1e9 + 7;
#define pb push_back
typedef vector<char> vcc;
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
        ll n; cin >> n;
        vll arr(n, 0), dp(n, 0);

        for (ll i = 0; i < n; ++i)
        {
            cin >> arr[i];
            dp[i] = 0;
        }

        ll ans = 0;
        for (ll i = 0; i < n; ++i)
        {
            dp[i] = 1;
            for (ll j = (i >> 8 << 8); j < i; ++j)
            {
                if ((arr[j] ^ i) < (arr[i] ^ j))
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ans = max(ans, dp[i]);
        }
        cout << ans << endl;
        dp.clear(), arr.clear();
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