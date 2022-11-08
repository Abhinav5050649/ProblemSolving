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

        map<ll, ll> m1, m2;

        for (ll i = 0; i < n; ++i)
        {
            ll num; cin >> num;
            m1[num]++;
        }

        for (ll i = 0; i < n; ++i)
        {
            ll num; cin >> num;
            m2[num]++;
        }
        
        ll one1 = m1[1], zero1 = m1[0], one2 = m2[1], zero2 = m2[0];

        if ((zero1 == n && zero2 == n) || (one1 == n && one2 == n))
        {
            cout << 0 << '\n';
        }
        else{
            if ((one1 == one2 && one1 != n) || (zero1 == zero2 && zero1 != n))
            {
                
            }
        }
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