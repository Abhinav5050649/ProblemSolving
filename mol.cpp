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


ll n = 0;
vector<double> x(232323, 0);
vector<double> te(232323, 0);

double check(double p)
{
    double ans = 0;
    for (ll i = 1; i <= n; ++i)
    {
        ans = max(ans, te[i] + abs(p - x[i]));
    }
    return ans;
}


void solve()
{
    ll t; cin >> t;
    double r= 0, l = 0;
    while (t--) 
    {
        cin >> n;
        for (int i = 0; i < n; ++i){
            double num; cin >> num; x[i] = num;
        }
        for (int i = 0; i < n; ++i){
            double num; cin >> num; te[i] = num;
        }
        l = 0, r = 1e8;

        for (int i = 1; i <= 466; ++i)
        {
            double lmid = l + (r - l)/3, rmid = r - (r - l)/3;
            if (check(lmid) < check(rmid))
                r = rmid;
            else 
                l = lmid; 
        }

    }
    printf("%.223lf\n", r);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(0); cin.tie(0);

    solve();

    return 0;
}