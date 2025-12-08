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
  int n;
  cin >> n;
  vector<string> s(n);
  rep(i, 0, n) cin >> s[i];
  bool res = false;
  rep(i, 0, n) rep(j, 0, n)
  {
    if (i + 5 < n)
    {
      int cnt = 0;
      rep(d, 0, 6) if (s[i + d][j] == '#') cnt++;
      if (cnt >= 4)
      {
        cout << "Yes" << endl;
        return 0;
      }
    }
    if (j + 5 < n)
    {
      int cnt = 0;
      rep(d, 0, 6) if (s[i][j + d] == '#') cnt++;
      if (cnt >= 4)
      {
        cout << "Yes" << endl;
        return 0;
      }
    }
    if (i + 5 < n and j + 5 < n)
    {
      int cnt = 0;
      rep(d, 0, 6) if (s[i + d][j + d] == '#') cnt++;
      if (cnt >= 4)
      {
        cout << "Yes" << endl;
        return 0;
      }
    }
    if (i + 5 < n and j - 5 >= 0)
    {
      int cnt = 0;
      rep(d, 0, 6) if (s[i + d][j - d] == '#') cnt++;
      if (cnt >= 4)
      {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
}