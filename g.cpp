#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
#define pb push_back
const ll mod = 1e9 + 7;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<char> vc;
typedef vector<vc> vcc;

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
    ll n; cin >> n;
    for (ll i = 0, x = 1 << n; i < x; ++i)
    {
        ll val = i ^ (i >> 1);
        bitset<32> foo(val);
        string ans = foo.to_string();
        for (ll j = 32 - n; j < 32; ++j)    cout << ans[j];
        cout << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    solve();

    return 0;
}