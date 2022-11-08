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

ll bin_exp(ll a, ll b, ll m)
{
    a %= m;
    ll res = 1;

    while (b > 0)
    {
        if (b & 1)  res = res * a % m;
        a = a * a % m;
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

ll bin_exp_2(ll a, ll b, ll m){
    ll res = 1;
    a %= m;

    while (b > 0)
    {
        if (b & 1)  res =  res * a % m;
        a = a * a % m;
        b >>= 1;
    }

    return res;
}

void solve()
{
    ll n; cin >> n;
    while (n--){
        ll a, b, c; cin >> a >> b >> c;

        ll r = bin_exp_2(b, c, mod - 1);
        cout << bin_exp_2(a, r, mod) << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(0), cin.tie(0);

    solve();

    return 0;
}