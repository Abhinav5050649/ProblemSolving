#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
const ll MOD = 1e9 + 7;
#define pb push_back;

ll bin_exp(ll a, ll b)
{   
    /*
        if (b == 0) return 1;
        ll res = bin_exp(a, b/2);
        if (b % 2)  return res * res * a;
        else    return res * res;    
    */

   /*
   if (b == 0)  return 1;
   ll res = bin_exp(a, b / 2);

    if (b % 2)   return (res * res * a % MOD);
    else    return (res * res % MOD);
    */

   /*
   ll res = 1;
   while (b > 0)
   {
        if (b & 1)  res = res * a;
        a = a * a;
        b >>= 1;
   }
   return res;
   */

    a %= MOD;
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)  res = res *a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void solve()
{
    ll n; cin >> n;

    cout << bin_exp(2, n) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    solve();

    return 0;
}