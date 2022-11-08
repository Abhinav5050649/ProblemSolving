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

int st[N];

void solve(){
    ll t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        ll T = INF;
        ll n = s.length();
        for (ll i = 0; i < n + 10; ++i) st[i] = 0;

        for (ll i = n - 1; i >= 0; --i)
        {
            if (T >= s[i] - '0')    T = s[i] - '0';
            else    st[i] = 1;
        }

        string ss = "";

        for (ll i = 0; i < n; ++i)
        {
            if (st[i])  ss += (s[i] == '9') ?   '9'  :   (char)(s[i] + 1);
            else    ss += s[i];
        }

        sort(ss.begin(), ss.end());
        cout << ss << endl;
    }
}
/*
void solve()
{
    ll t; cin >> t;
    while (t--)
    {
        string s; cin >> s;

        ll x = s.size();

        for (ll i = 0; i < x + 10; ++i) st[i] = 0;

        ll T = INF;

        for (ll i = x - 1; i >= 0; --i)
        {
            if (T >= s[i] - '0')    T = s[i] - '0';
            else    st[i] = 1;
        }

        string ss = "";

        for (ll i = 0; i < x; ++i)
        {
            if (st[i])  ss += (s[i] == '9') ? '9' : (char)(s[i] + 1);
            else    ss += s[i];
        }

        sort(ss.begin(), ss.end());

        cout << ss << endl;

    }
}
*/

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(0), cin.tie(0);

    solve();

    return 0;
}