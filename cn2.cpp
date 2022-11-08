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
    ll n, m; cin >> n >> m;
    ll ind[n + 2] = {0}, a[n + 1] = {0};
    ind[n + 1] = n + 1;

    for (ll i = 1; i <= n; ++i)
    {
        ll x; cin >> x;
        ind[x] = i;
        a[i] = x;
    }

    ll l = 1;
    ll c= 1;
    for (ll i = 1; i <= n; ++i)
    {
        if (l > ind[i])
        ++c;
        l = ind[i];
    }

    while (m--)
    {
        ll x, y; cin >> x >> y;
        ll r = a[x], s = a[y];
        swap(a[x], a[y]);

        if (ind[r - 1] <= ind[r] && ind[r - 1] > y) ++c;
        if (ind[r-1] > ind[r] && ind[r - 1] <= y)   --c;
        if (ind[r] <= ind[r + 1] && y > ind[r + 1]) ++c;
        if (ind[r] > ind[r + 1] && y <= ind[r + 1]) --c;
        ind[r] = y;
        if (ind[s - 1] <= ind[s] && ind[s- 1] > x)  ++c;
        if (ind[s - 1] > ind[s] && ind[s- 1] <= x)  --c;
        if (ind[s] <= ind[s + 1] && x > ind[s + 1]) ++c;
        if (ind[s] > ind[s + 1] && x <= ind[s + 1]) --c;
        ind[s] = x;
        cout << c << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(0), cin.tie(0);

    solve();

    return 0;
}