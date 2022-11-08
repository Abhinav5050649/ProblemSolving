#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
#define pb push_back
const ll mod = 1e9 + 7;
typedef vector<ll> vll;

void solve()
{
    ll n; cin >> n;
    vll arr, v, v1, v2;

    ll sum = (n * (n + 1)) /2;

    for (ll i = 1; i <= n; ++i) arr.pb(i);

    if (sum % 2 == 0)
    {
        cout << "YES" << endl;

        if (n % 4 == 0)
        {
            for (ll i = 1; i <= n/4; ++i)   v1.pb(i);
            for (ll i = 0; i < n/4; ++i)    v1.pb(arr[n - i - 1]);
            for (ll i = n/4; i < v1[v1.size()- 1] - 1; ++i)    v2.pb(arr[i]);
        }
        else if (n % 4 == 3)
        {
            for (ll i = 4; i <= n; ++i) v.pb(i);
            v1.pb(1), v1.pb(2), v2.pb(3);

            for (ll i = 0; i < (n - 3)/4; ++i){
                v1.pb(v[i]);
                v1.pb(v[v.size() - i - 1]);
            }

            for (ll i = 4 + (n - 3)/4; i <= n - (n - 3)/4; ++i)    v2.pb(i);
        }

        cout << v1.size() << endl;
        for (auto it: v1)   cout << it << " ";
        cout << endl;

        cout << v2.size() << endl;
        for (auto it: v2)   cout << it << " ";
        cout << endl;

    }else{
        cout << "NO" << endl;
    }
    arr.clear(), v1.clear(), v2.clear(), v.clear();

}

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    
    solve();

    return 0;
}