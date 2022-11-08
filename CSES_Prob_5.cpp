#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef vector<ll> vll;

void solve(){
    ll n; cin >> n;

    if (n == 1)
    {
        cout << "1" << endl;
        return;
    }
    else if (n == 2 || n  == 3)
    {
        cout << "NO SOLUTION" << endl;
        return;
    } 

    
    vll odd, even;

    for (ll i = 1; i <= n; ++i)
    {
        (i % 2 == 0) ? even.push_back(i) : odd.push_back(i);
    }
    
    even.insert(even.end(), odd.begin(), odd.end());

    for (ll i = 0; i < n; ++i){
        cout << even[i] << " ";
    }
    cout << endl;

    even.clear(), odd.clear();
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(0), cin.tie(0);

    solve();
    return 0;
}