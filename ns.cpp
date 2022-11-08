#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
const ll MOD = 1e9 + 7;
#define pb push_back;

ll bin_exp(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

void solve()
{
    ll t; cin >> t;

    while (t--)
    {
        ll x, y; cin >> y >> x;

        if (x > y)
        {
            if (x % 2)
                cout << (bin_exp(x, 2) - y + 1) << endl;
            else 
                cout << (bin_exp(x - 1, 2) + y) << endl;
        }   
        else
        {
            if (y % 2)
                cout << (bin_exp(y - 1, 2) + x) << endl;
            else
                cout << (bin_exp(y, 2) - x + 1) << endl;
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