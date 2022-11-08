#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
const ll mod = 1e9 + 7;
#define pb push_back
typedef vector<vl> vll;
typedef vector<char> vc;
typedef vector<vc> vcc;
typedef vector<int> vi;
typedef vector<vi> vii;

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

void solve(){

    ll n; cin >> n;
    set<ll> s;
    
    for (ll i = 0; i < n; ++i)
    {
        ll num; cin >> num; s.insert(num);
    }
    cout << s.size() << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    solve();

    return 0;
}