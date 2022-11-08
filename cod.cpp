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

const ll max_v_sz = 1e6 + 6;

//Poland Rho's Algorithm??  --> Helpful for finding factors of numbers
ll spf[max_v_sz];   //Helpful for storing details related to factors of numbers

void sievespf(ll n)
{
    for (ll i = 1; i <= n - 1; ++i) spf[i] = i;

    for (ll p = 2; p * p <= n - 1; ++p)
    {
        if (spf[p] == p)
        {
            for (ll i = p * p; i <= n - 1; i += p)
            {
                if (spf[i] == i)    spf[i] = p;
            }
        }
    }
}

vll prime()
{
    ll N = 1e6 + 5;
    vll pNo(1e6 + 5, 1);
    pNo[0] = 0;
    pNo[1] = 0;

    for (ll i = 2; i * i <= N; ++i)
    {
        for (ll j = i * i; j <= N; j += i)
        {
            pNo[j] = 0;
        }
    }

    return pNo;
}

void solve()
{
    sievespf(max_v_sz);

    ll n; cin >> n;
    while (n--)
    {
        ll x; cin >> x;
        ll ans = 1;
        
        while (x != 1)
        {
            ll y = spf[x];
            ll c = 1;
            while (x % y == 0)
            {
                ++c, x /= y;
            }
            ans *= c;
        }

        cout << ans << '\n';
        
        /*
        for (ll i = 1; i * i <= x; ++i)
        {
            if (x % i == 0)
            {
                ++cnt;
                if (i * i != n) ++cnt;
            }
        }
        */

        /*
        if (primes[x])  cout << 2 << '\n';
        else
        {
            for (ll i = 1, m = sqrt(x); i <= m; ++i)
            {
                if (i == m && i * i == x)   cnt += 1;
                else if (x % i == 0)  cnt += 2; 
            }
            cout << cnt << '\n';
        }
        */
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    //vll primes = prime();

    solve();

    //primes.clear();
    return 0;
}