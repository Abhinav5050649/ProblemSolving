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

void solve(){
    
    ll t; cin >> t;
    while (t--)
    {
        ll n; cin >> n;
        vll arr(n + 1, 0), vis(n + 1, 0);

        for (ll i = 1; i <= n; ++i) cin >> arr[i];
        
        if (n == 1) {cout << 0 << endl; continue;}

        cout << n - 1<< endl;
        cout << 1 << " " << n << endl;
        for (ll i = 2; i <n; ++i)
        {
            if ((arr[i] + arr[1]) % 2)  cout << 1 << " " << i << endl;  vis[i] = 1; 
        }

        for (ll i = n - 1; i > 1; --i)
        {
            if (!vis[i])    cout << i << " " << n << endl;
        }

        arr.clear(), vis.clear();
    }   
}

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(0), cin.tie(0);

    solve();

    return 0;
}