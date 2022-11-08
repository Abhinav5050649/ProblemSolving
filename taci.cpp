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
    ll n = 0, s = 0, count[5] = {0};
    cin >> n;
    for (ll i = 0; i < n; ++i)
    {
        cin >> s;
        count[s] += 1;
    }

    ll total = count[2] + count[3] + count[4] / 2;
    count[1] -= count[3];

    if (count[2] % 2 == 1)
    {
        total += 1;
        count[1] -= 2;
    }

    if (count[1] > 0)
    {
        total += (count[1] + 3)/4;
    }

    cout << total << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(0), cin.tie(0);

    solve();

    return 0;
}