#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  if (s[0] == '1')
  {
    cout << "No" << endl;
    return 0;
  }
  vector<bool> stand(7);
  stand[0] = (s[6] == '1');
  stand[1] = (s[3] == '1');
  stand[2] = (s[1] == '1') or (s[7] == '1');
  stand[3] = (s[0] == '1') or (s[4] == '1');
  stand[4] = (s[2] == '1') or (s[8] == '1');
  stand[5] = (s[5] == '1');
  stand[6] = (s[9] == '1');
  rep(i, 0, 7) rep(j, 0, i)
  {
    if (stand[i] and stand[j])
    {
      rep(k, j + 1, i)
      {
        if (!stand[k])
        {
          cout << "Yes" << endl;
          return 0;
        }
      }
    }
  }
  cout << "No" << endl;
}