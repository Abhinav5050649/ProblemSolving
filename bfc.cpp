#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
const ll mod = 1e9 + 7;
#define pb push_back

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
       ll a, b, c, d; cin >> a >> b >> c >> d;
       ll g = gcd(a, b);
       a/=g, b/=g;
       g = gcd(c, d);
       c /= g, d /=g;

       if ((a == c && b == d) || (a == c && a == 0))    cout << 0 << endl;
       else if ((a == 0 || c == 0)) cout << 1 << endl;
       else{
            ll aa = a *d , bb = b * c;
            if (aa < bb)    swap(aa, bb);   
            if (aa % bb == 0)   cout << 1 << endl;
            else    cout << 2 << endl;
       }
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