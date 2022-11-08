#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
const ll MOD = 1e9 + 7;
#define pb push_back;

void solve()
{
    ll t; cin >> t;
    while (t--)
    {
        ll a, b; cin >> a >> b;
        
        if (max(a, b) > (2 * min(a, b)))
            cout << "NO" << endl;
        else
        {
            if ((a + b) % 3 == 0)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
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