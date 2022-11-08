#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
#define pb push_back
const ll mod = 1e9 + 7;
typedef vector<ll> vll;
typedef vector<int> vii;
typedef vector<char> vc;
typedef vector<vector<char>> vcc;

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

vcc chess;

bool rd[15], ld[15], row[7];
ll c = 0;

void rec(ll j)
{
    if (j == 8){
        ++c; return;
    }

    for (ll i = 0; i < 8; ++i)
    {
        if (chess[i][j] == '.' && ld[i - j + 7] == 0 && rd[i + j] == 0 && row[i] == 0)
        {
            ld[i - j + 7] = 1, rd[i + j] = 1, row[i] = 1;
            rec(j + 1);
            ld[i - j + 7] = 0, rd[i + j] = 0, row[i] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    for (ll i = 0; i < 8; ++i)
    {
        vc v;
        for (ll j = 0; j < 8; ++j)
        {
            char ch; cin >> ch; v.pb(ch);
        }
        chess.pb(v);
    }

    rec(0);

    cout << c << endl;
    chess.clear();
    return 0;
}