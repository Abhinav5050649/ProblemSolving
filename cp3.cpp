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


ll dict[27], used[27], to[27]; 
ll cnt = 0;

/*
ll dict[27], to[27], used[27], cnt = 0;

bool check(ll u, ll v, ll start)
{
    if (v != start)
    {
        if (to[v] == 0) return true;
        ++cnt;
        return check(v, to[v], start);
    }else if(v == start)
    {
        if (cnt == 25)  return true;
        else return false;
    }
    return false;
}

void solve()
{
    ll t; cin >> t;
    while (t--)
    {
        memset(to, 0, sizeof(to));  memset(dict, 0, sizeof(dict)); memset(used, 0, sizeof(used));
        ll n; cin >> n;
        string s; cin >> s;

        for (ll i = 0; i < n; ++i)
        {
            ll ind = char(s[i]) - 'a' + 1;
            if (dict[ind])
            {
                cout << char(dict[ind] + 'a' - 1);
            }else{
                for (ll j = 1; j <= 26; ++j)
                {
                    cnt = 0;
                    if (!used[j])
                    {
                        if (check(j, ind, j))
                        {
                            dict[ind] = j;
                            to[j] = ind;
                            used[j] = 1;
                            break;
                        }
                    }
                }

                cout << char(dict[ind] + 'a' - 1);
            }
        }
        cout << endl;
    }
}
*/

bool check(ll u, ll v, ll start)
{
    if (v != start)
    {
        if (to[v] == 0) return true;
        ++cnt;
        return check(v, to[v], start); 
    }
    else if (v == start) {
        if (cnt == 25)  return true;
        else    return false;
    }
    return false;
}

void solve()
{
    ll t; cin >>t;
    while (t--)
    {
        memset(used, 0, sizeof(used)); memset(dict, 0, sizeof(dict)); memset(to, 0, sizeof(to));
        ll n; cin >> n;
        string s; cin >> s;

        for (ll i = 0; i < n; ++i)
        {
            ll ind = char(s[i]) - 'a' + 1;
            if (dict[ind])
            {
                cout << char(dict[ind] + 'a' - 1);                
            }
            else{
                for (ll j = 1; j <= 26; ++j)
                {
                    cnt = 0;
                    if (!used[j])
                    {
                        if (check(j, ind, j))
                        {
                            dict[ind] = j;
                            to[j] = ind;
                            used[j] = 1;
                            break;
                        }
                    }
                }
                cout << char(dict[ind] + 'a' - 1);
            }
        }
        cout << endl;
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