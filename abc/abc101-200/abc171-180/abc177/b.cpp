#include <bits/stdc++.h>
using namespace std;
#define rep(j, a, b) for (int j = (a); j < (b); j++)
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
  int ans = t.size() + 1;
  rep(i, 0, s.size() - t.size() + 1)
  {
    int diff = 0;
    rep(j, 0, t.size()) if (t[j] != s[i + j]) diff++;
    ans = min(ans, diff);
  }
  cout << ans << endl;
}