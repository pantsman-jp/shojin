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
  set<P> st;
  vector<P> ps;
  rep(i, 0, 9)
  {
    string s;
    cin >> s;
    rep(j, 0, 9) if (s[j] == '#') st.emplace(i, j), ps.emplace_back(i, j);
  }
  int n = ps.size(), ans = 0;
  rep(ai, 0, n) rep(bi, 0, n) if (ai != bi)
  {
    P a = ps[ai], b = ps[bi];
    int di = b.first - a.first, dj = b.second - a.second;
    P c(b.first - dj, b.second + di), d(c.first - di, c.second - dj);
    if (st.count(c) and st.count(d))
      ans++;
  }
  cout << ans / 4 << endl;
}