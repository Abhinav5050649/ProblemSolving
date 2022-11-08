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
    ll arr[2][2];
    ll t; cin >> t;
    while (t--)
    {
        ll cnt = 0;
        for (ll i = 0; i < 2; ++i) for (ll j = 0; j < 2; ++j)   {cin >> arr[i][j]; cnt += arr[i][j];}

        if (cnt == 4)   cout << 2 << endl;
        else if (cnt == 0)  cout << 0 << endl;
        else    cout << 1 << endl;
    }
     
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(0), cin.tie(0);

    solve();

    return 0;
}