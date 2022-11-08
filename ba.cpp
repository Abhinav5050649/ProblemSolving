#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
#define pb push_back
typedef vector<ll> vll;
const ll MOD = 1e9 + 7;

void solve()
{
    ll t; cin >> t;

    while (t--)
    {
        ll n, k, b, s; cin >> n >> k >> b >> s;

        if ((k * b) > s || s > ((k * b) + (n * (k - 1))))    cout << "-1" << endl;
        else{
            vll arr(n, 0);
            arr[n - 1] = k * b;
            s -= k * b;

            for (int i = n - 1; i >= 0 && s > 0; --i)
            {
                arr[i] += min(k - 1, s);
                s -= min(k - 1, s);
            }

            for (int i = 0; i < n; ++i) cout << arr[i] << " ";
            cout << endl;
            arr.clear();
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