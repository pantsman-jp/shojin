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
  string s, t;
  cin >> s >> t;
  string ans = "UNRESTORABLE";
  rep(i, 0, s.size() - t.size() + 1)
  {
    bool ok = true;
    string tmp = s;
    rep(j, 0, t.size())
    {
      if (s[i + j] != '?' and s[i + j] != t[j])
        ok = false;
      tmp[i + j] = t[j];
    }
    if (ok)
    {
      rep(j, 0, tmp.size()) if (tmp[j] == '?') tmp[j] = 'a';
      if (ans == "UNRESTORABLE")
        ans = tmp;
      else
        ans = min(ans, tmp);
    }
  }
  cout << ans << endl;
}