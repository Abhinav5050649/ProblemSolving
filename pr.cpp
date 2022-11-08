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

bool isPal(string s, ll len)
{
    for (ll i = 0; i <= len/2; ++i)
    {
        if (s[i] != s[len - i - 1]) return false;
    }

    return true;
}

void solve()
{
    vll fs(26, 0);
    string s; cin >> s;
    ll len = s.length();

    for (ll i = 0; i < len; ++i)    ++fs[s[i] - 65];

    ll cnt = 0;
    for (ll i = 0; i < 26; ++i){
        if (fs[i] % 2 != 0) ++cnt; 
    }

    if (cnt > 1)    cout << "NO SOLUTION" << endl;
    else{
        vector<char> v1, v2;
        for (ll i = 0; i < 26; ++i)
        {
            if (fs[i] % 2 == 0) 
            {
                for (ll j = 0; j < fs[i]/2; ++j)    v1.pb(i + 65);
            }
            else
            {
                for (ll j = 0; j < fs[i]; ++j)  v2.pb(i + 65);
            }
        }

        for (ll i = 0, n = v1.size(); i < n; ++i)   cout << v1[i] << "";
        for (ll i = 0, n = v2.size(); i < n; ++i)   cout << v2[i] << "";
        for (ll i = v1.size() - 1; i >= 0; --i) cout << v1[i] << "";
        cout << endl;
        v1.clear(), v2.clear();
    }

    fs.clear();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    solve();

    return 0;
}