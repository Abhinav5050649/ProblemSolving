#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
#define pb push_back
const ll mod = 1e9 + 7;
typedef vector<ll> vll;

void solve()
{
    ll n; cin >> n;
    vll arr, v1, v2;
    
    for (ll i = 0; i < n; ++i)  arr.pb(i + 1);

    ll sum = (n * (n + 1))/2;

    if (sum % 2 == 0)
    {
        cout << "YES" << endl;
        if (n % 4 == 0)
        {
            for (ll i = 1; i <= n/4; ++i)   v1.pb(i);
            for (ll i = 0; i < n/4;  ++i)    v1.pb(arr[n - i - 1]);
            for (ll i = n/4 + 1; i < v1[v1.size() - 1]; ++i)    v2.pb(i);     
        }
        else if (n % 4 == 3)
        {
            vll v;
            for (ll i = 4; i <= n; ++i) v.pb(i);
            v1.pb(1), v1.pb(2), v2.pb(3);
            for (ll i = 0; i < (n - 3)/4; ++i)
            {
                v1.pb(v[i]);
                v1.pb(v[v.size() - i - 1]);
            }
            for (ll i = 4 + (n - 3)/4; i <= n - (n - 3)/4; ++i) v2.pb(i);
            v.clear();
        }

        cout << v1.size() << endl;
        for (ll i = 0, n = v1.size(); i < n; ++i)  cout << v1[i] << " ";
        cout << endl;

        cout << v2.size() << endl;
        for (ll i = 0, n = v2.size(); i < n; ++i)  cout << v2[i] << " ";
        cout << endl;   
    }
    else 
    {
        cout << "NO" << endl;
    }
    v1.clear(), v2.clear(), arr.clear();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    solve();

    return 0;
}