#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
#define pb push_back
typedef vector<ll> vll;
typedef vector<int> vii;

const ll mod = 1e9 + 7;
const ll NE = 1e6 + 5;
const ll max_v_sz = 1e6 + 6;

void swap(ll &a, ll &b)
{
    a ^= b; b ^= a; a ^= b;
}

// for simple a ^ b
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

//for calculating (a ^ (b ^ c))
ll bin_exp_2(ll a, ll b, ll m)
{
    a %= m;
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)  res = res * a % m;
        a = a * a % m;
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


vll pNo(1e6 + 5, 1);    //Stores all primes till 1e6 + 5

//Poland Rho's Algorithm??  --> Helpful for finding factors of numbers
ll spf[max_v_sz];   //For storing details related to factors of numbers

//Method to implement Poland Rho's Algo
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

//Sieve of eratosthenes
vll prime()
{
    pNo[0] = 0;
    pNo[1] = 0;

    for (ll i = 2; i * i <= NE; ++i)
    {
        for (ll j = i * i; j <= NE; j += i)
        {
            pNo[j] = 0;
        }
    }

    return pNo;
}


//--------------------------------------Solving starts here--------------------------------------------------------
void solve()
{
    ll t; cin >> t;
    while (t--)
    {
        ll n; cin >> n;
        vll arr(n, 0);

        for (ll &x: arr)    cin >> x;

        sort(arr.begin(), arr.end());

        cout << arr[n - 1] - arr[0] << '\n';
        arr.clear();
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