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
        ll n, m, k; cin >> n >> m >> k;
        string s1, s2; cin >> s1 >> s2;

        ll st1 = 0, st2 = 0, x = 0, y = 0;

        sort(s1.begin(), s1.end()), sort(s2.begin(), s2.end());

        string s = "";

        while (st1 < n && st2 < m)
        {
            if ((s1[st1] < s2[st2] && x < k) || y == k)
            {
                s.pb(s1[st1]); st1++, x++, y = 0;
            }
            else
            {
                s.pb(s2[st2]); st2++, y++, x = 0;
            }
        }
        cout << s << endl;
    }
}
/*
void solve()
{
    ll t; cin >> t;
    while (t--)
    {
        ll n, m, k; cin >> n >> m >> k;
        string s1, s2; cin >> s1 >> s2;

        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());

        string ans = "";

        ll st1 = 0, st2 = 0, x = 0, y = 0;

        while (st1 < n && st2 < m)
        {
            if ((s1[st1] < s2[st2] && x < k) || y == k)
            {
                ans.pb(s1[st1]);
                st1++, x++, y = 0;
            }
            else
            {
                ans.pb(s2[st2]);
                st2++, y++, x = 0;
            }
        }

        cout << ans << endl;
    }
}
*/

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(0), cin.tie(0);

    solve();

    return 0;
}