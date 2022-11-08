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
    while (t--){
        ll n; cin >> n;

        vll a(n, 0), b(n, 0);
        for (ll &x: a)  cin >> x;
        for (ll &x: b)  cin >> x;

        unordered_map<ll, ll> m1, m2;

        for (auto it: a)    m1[it]++;
        for (auto it: b)    m2[it]++;

        if ((m1[1] == m2[1] && m1[1] == n) || (m1[0] == m2[0] && m1[0] == n))   cout << 0 << endl;
        else{
            
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