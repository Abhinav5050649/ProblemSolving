#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
#define pb push_back
const ll mod = 1e9 + 7;
typedef vector<ll> vll;
typedef vector<int> vii;
const ll Max_N = 1e9 + 1;
vll prime1(10000000, 1), prime2(10000000, 1);

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
        if (n == 1)
        {
            cout << 2 << endl;
            continue;
        }
        else if (n == 2)
        {
            cout << 4 << endl;
            continue;
        }
        else if (n == 3)
        {
            cout << 7 << endl;
            continue;
        }
        else if (n > 3)
        {
            ll ans = 7;
            for (ll i = 2; i <= n; ++i)
            {
                ll cnt = 0;
                if (i > 10000000)
                {
                    if (prime2[i % 10000000] == 1)
                    {
                        ll temp = i;
                        while (cnt < 3 && temp <= n){
                            temp += i;
                            ++cnt;
                        }   
                        ans += cnt;
                    }
                }
                else{
                    if (prime1[i] == 1)
                    {
                        ll temp = i;
                        while (cnt < 3 && temp < n){
                            temp += i;
                            ++cnt;
                        }   
                        ans += cnt;
                    }
                }
            }
            cout << ans << endl;
            continue;
        }
    }
}

int main()
{
    //Sieve of Erato
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    prime1[0] = 0, prime1[1] = 0;
    for (ll i = 2; i * i <= Max_N; ++i)
    {
        for (ll j = i * i; j <= Max_N; j += (i + 1))
        {

            if (j > 10000000)
            {
                prime2[j % 10000000] = 0;
            }
            else{
                prime1[j] = 0;
            }
        }
    }

    solve();

    prime1.clear(), prime2.clear();
    return 0;
}