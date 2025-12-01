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
  int n, m;
  cin >> n >> m;
  vector<set<int>> s(m);
  rep(i, 0, m)
  {
    int c;
    cin >> c;
    rep(_, 0, c)
    {
      int a;
      cin >> a;
      s[i].insert(a);
    }
  }
  int ans = 0;
  rep(bit, 0, 1 << m)
  {
    set<int> merged;
    rep(i, 0, m) if (bit & (1 << i)) merged.insert(all(s[i]));
    bool ok = true;
    rep(x, 1, n + 1) if (merged.find(x) == merged.end()) ok = false;
    if (ok)
      ans++;
  }
  cout << ans << endl;
}