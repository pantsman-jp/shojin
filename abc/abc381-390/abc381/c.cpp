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
  string s;
  cin >> n >> s;
  int ans = 0;
  rep(i, 0, n)
  {
    if (s[i] != '/')
      continue;
    else
    {
      int diff = 1, tmp = 1;
      while (true)
      {
        if (i - diff < 0 or n - 1 < i + diff)
          break;
        if (s[i - diff] != '1' or s[i + diff] != '2')
          break;
        tmp = diff * 2 + 1, diff++;
      }
      ans = max(ans, tmp);
    }
  }
  cout << ans << endl;
}