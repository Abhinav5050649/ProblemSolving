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
    while (t--)
    {
        ll n, q; cin >> n >> q;
        
        ll sum_of_even = 0, cnt_even = 0, sum_of_odd = 0, cnt_odd = 0;

        vll arr(n, 0);

        for (ll &x: arr)
        {
            cin >> x;

            (x % 2 == 0) ? (sum_of_even += x, cnt_even++)  :   (sum_of_odd += x, cnt_odd++);  
        }

        while (q--)
        {
            ll type = -1, x = -1;
            cin >> type >> x;

            if (type == 1)
            {
                cout << cnt_odd*x + sum_of_even + sum_of_odd << endl;
                sum_of_odd += cnt_odd*x;
            }  
            else
            {
                cout << cnt_even*x + sum_of_even + sum_of_odd << endl;
                sum_of_even += cnt_even*x;
            }
        }

        arr.clear();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(0), cin.tie(0);

    solve();

    return 0;
}