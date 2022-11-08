#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;
typedef vector<ll> vll;

void dpMethod1(vll &nums, ll sum, ll n, ll &cnt, ll index)
{
    // if (sum == n)
    // {
    //     cnt++;
    // }
    // else if ()
    // {
    //     return;
    // }
    if (index >= nums.size() || sum != n)
    {
        return;
    }
    else if (sum == n)
    {
        ++cnt;
        return;
    }
    else
    {
        dpMethod1(nums, sum + nums[index], n, cnt, index);
        dpMethod1(nums, sum + nums[index + 1], n, cnt, index + 1);
    }
}

void solve()
{
    ll n; cin >> n;
    vll nums = {1, 2, 3, 4, 5, 6};
    ll cnt = 0;

    dpMethod1(nums, 0, n, cnt, 0);

    cout << cnt << endl;
    nums.clear();
    return;
}

int main()
{
    cout.tie(0);
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    solve();

    return 0;
}