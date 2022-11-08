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

void solve()
{
    ll t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        ll len = s.length();
        
        ll subString = 0, cnt = 0;
        
        for (ll i = 0; i < len; ++i)
        {
            if ((s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') && (s[i + 1] == 'a' || s[i + 1] == 'e' || s[i + 1] == 'i' || s[i + 1] == 'o' || s[i + 1] == 'u'))
            {
                ++cnt;
            }
            else
            {
                if (s[i] != 'a' || s[i] != 'e' || s[i] != 'o' || s[i] != 'i' || s[i] != 'u')
                {
                    cnt = 0;
                    if (s[i + 1] != 'a' || s[i + 1] != 'e' || s[i + 1] != 'o' || s[i + 1] != 'i' || s[i + 1] != 'u')
                    {
                        ++i;
                    }
                }
            }
            
            subString = max(cnt, subString);
        }
        
        if (subString > 2)  cout << "Happy\n";
        else    cout << "Sad\n";
    }
}

int main()
{
    IO; ct; ci;
    
    solve();
    
    return 0;
}