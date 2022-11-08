#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

void solve()
{
	vector<vector<string>> vvs;
	int n; cin >> n;

	for (int i= 0; i < 3; ++i)
	{
		vector<string> str;

		for (int j = 0; j < n; ++j)
		{
			string s; cin >> s;
			str.push_back(s);
		}
		vvs.push_back(str);
		str.clear();
	}

	int cnt_a = 0, cnt_b = 0, cnt_c = 0;
	for (int j = 0; j < n; ++j)
	{
		if ((vvs[0][j] != vvs[1][j] && vvs[0][j] != vvs[2][j] && vvs[1][j] != vvs[2][j]))
		{
			cnt_a += 3, cnt_b += 3, cnt_c += 3;
		}
		else if (vvs[0][j] == vvs[1][j] && vvs[2][j] == vvs[0][j])
		{
			cnt_a += 0, cnt_b += 0, cnt_c += 0;
		}
		else
		{
				if ((vvs[0][j] != vvs[1][j] && vvs[0][j] == vvs[2][j]))
				{
					cnt_a += 1, cnt_c += 1, cnt_b += 3;
				}
				else if ((vvs[0][j] == vvs[1][j] && vvs[0][j] != vvs[2][j]))
				{
					cnt_a += 1, cnt_b +=1, cnt_c += 3;
				}
				else if ((vvs[1][j] == vvs[2][j] && vvs[1][j] != vvs[0][j]))
				{
					cnt_b += 1, cnt_c += 1, cnt_a += 3;
				}
		}
	}

	vvs.clear();
	cout << cnt_a << " " << cnt_b << " " << cnt_c << "\n";
	return;
}

int main()
{
	int t; cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}