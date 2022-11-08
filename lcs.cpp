#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
#define pb push_back
typedef vector<ll> vll;
typedef vector<int> vii;
typedef vector<char> vcc;
#define IO ios_base::sync_with_stdio(false);
#define ct cout.tie(0);
#define ci cin.tie(0);

ll max_dp_solve(string A, string B, ll ind1, ll ind2, ll n)
{
    if (ind1 >= n || ind2 >= n)
    {
        return 0;
    }

    if (A[ind1] == B[ind2])
    {
        return (1 + max_dp_solve(A, B, ind1 + 1, ind2 + 1, n));
    }
    else
    {
        return max(max_dp_solve(A, B, ind1 + 1, ind2, n), max_dp_solve(A, B, ind1, ind2 + 1, n));
    }
}

ll min_dp_solve(string A, string B, ll ind1, ll ind2, ll n)
{
    if (ind1 >= n || ind2 >= n)
    {
        return 0;
    }

    if (A[ind1] == B[ind2])
    {
        return (1 + min_dp_solve(A, B, ind1 + 1, ind2 + 1, n));
    }
    else
    {
        return min(min_dp_solve(A, B, ind1 + 1, ind2, n), min_dp_solve(A, B, ind1, ind2 + 1, n));
    }
}

void solve()
{
    ll t; cin >> t;
    while (t--)
    {
        ll n; cin >> n;
        string A, B; cin >> A >> B;
        
        ll ind1 = 0, ind2 = 0;
        ll max_ans = max_dp_solve(A, B, ind1, ind2, n);
        ll min_ans = min_dp_solve(A, B, ind1, ind2, n);

        if (min_ans == 0 && max_ans != 0)   cout << max_ans << '\n';
        else    cout << min_ans << '\n';
        
    }
}

int main()
{
    IO; ct; ci;
    
    solve();
    
    return 0;
}