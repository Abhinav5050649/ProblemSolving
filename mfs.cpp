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
        vll a(n, 0), b(n, 0);
        for (ll &x: a) cin >> x;
        for (ll &x: b)  cin >> x;
        
        bool ft = false;
        for (ll i = 0; i < n; ++i)
        {
            if (a[i] > b[i])
            {
                ft = true;
                break;
            }
        }

        if (ft)
        {
            cout << "NO" << endl;
            continue;
        }

        for (ll i = n - 1; i > 0; --i)
        {
            if ((b[i - 1] - b[i] > 1) && (b[i - 1] != a[i - 1]))
            {
                ft = true;
                break;
            }
        }

        if ((b[n - 1] - b[0] > 1) && (b[n - 1] != a[n - 1])){
            ft = true;
        }

        if (ft){
            cout << "NO" << endl;
        }else{
            cout << "YES" << endl;
        }
        a.clear(), b.clear();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(0), cin.tie(0);

    solve();

    return 0;
}