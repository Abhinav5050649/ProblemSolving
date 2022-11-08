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
        ll n, k; cin >> n >> k;
        vll arr(n, 0);
        /*
        ll l = k - 1, r = k + 1, le = 0, re = 0, lim = 0, rim = 0;

        while (l >= 1 && r <= n)
        {
            ll f= 0;
            while (rim + le + arr[k] + arr[r] >= 0 && r <= n)
            {
                f = 1;
                rim += arr[r++];
                re = max(re, rim);
            }
            while (lim + re + arr[k] + arr[l] >= 0 && l >= 1)
            {
                f = 1;
                lim += arr[l--];
                le = max(le, lim);
            }
            if (!f) break;
        }

        (l == 0 || r == n - 1)  ?   (cout << "YES" << endl) :   (cout << "NO" << endl);*/
        
        for (ll &x: arr)    cin >> x;

        ll sum1 = arr[k - 1], sum2 = arr[k - 1], flag = -1;

        for (ll i = k - 2, j = k; i >= 0 && j < n; ++j, --i){ 
            sum1 += arr[i], sum2 += arr[j];

            if ((sum1 < 0) && (!(sum2 < 0))){
                sum1 = INT_MIN;
                continue;
            }else if ((!(sum1 < 0)) && (sum2 < 0)){
                sum2 = INT_MIN;
                continue;
            }   
            else if (sum1 < 0 && sum2 < 0)
            {
                flag = 1;
                break;
            }
            // ((sum1 < 0 && sum2 >= 0) || (sum1 >= 0 && sum2 < 0) || (sum1 >= 0 && sum2 >= 0)) ? flag = -1 : flag = 1;
            // if (flag == 1)  break;
        }
        (flag == 1) ?   (cout << "NO" << endl) :    (cout << "YES" << endl); 
        arr.clear();
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