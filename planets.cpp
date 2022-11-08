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
        unordered_map<ll, ll> m;
        ll n, c; cin >> n >> c;
        vll arr(n, 0);

        for (ll &x: arr)
        {
            cin >> x;
            m[x]++;
        }

        ll ans1 = 0, ans2 = 0, ans = 0;

        for (auto it: m){
            ans1 += it.second;
            if (it.second > 1){
                ans2 += c;
            }else{ans2 += it.second;}
            ans += min(ans1, ans2);
            ans1 = 0, ans2= 0;
        }
        cout << ans  << endl;
        m.clear();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(0), cin.tie(0);

    solve();

    return 0;
}