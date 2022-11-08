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
    ll n = 0, m = 0, k = 0, cnt = 0; cin >> n >> m >> k;
    vll a(n, 0), b(m, 0);
    for (ll &x: a)  cin >> x;
    for (ll &x: b)  cin >> x;

    sort(a.begin(), a.end()), sort(b.begin(), b.end());

    ll l1 = 0, l2 = 0;
    while (l1 < n && l2 < m)
    {
        if (abs(a[l1] - b[l2]) <= k)    ++cnt, ++l1, ++l2;
        else{
            if (a[l1] > b[l2])  ++l2;
            else    ++l1;
        }
    }
    cout << cnt;
    a.clear(), b.clear();
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(0), cin.tie(0);

    solve();

    return 0;
}