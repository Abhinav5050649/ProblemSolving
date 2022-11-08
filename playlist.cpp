#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
#define pb push_back
const ll mod = 1e9 + 7;
typedef vector<ll> vll;
typedef vector<int> vii;

const int N = 2e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

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
    ll n; cin >> n;
    vll arr(n, 0);
    for (ll &x: arr)    cin >> x;

    ll i = 0, j = 0, max_len = 0, curr_len = 0;
    map<ll, ll> freq;

    while (j < n)
    {
        if (freq.find(arr[j]) == freq.end() || freq[arr[j]] == 0)
        {
            ++curr_len;
            freq[arr[j]]++;
            ++j;
            max_len = max(max_len, curr_len);
        }
        else
        {
            curr_len--;
            freq[arr[i]]--;
            ++i;
        }
    }
    cout << max_len << endl;
    freq.clear(), arr.clear();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(0), cin.tie(0);

    solve();

    return 0;
}