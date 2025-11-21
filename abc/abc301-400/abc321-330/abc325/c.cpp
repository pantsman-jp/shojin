#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

const vector<int> di = {-1, -1, 0, 1, 1, 1, 0, -1};
const vector<int> dj = {0, -1, -1, -1, 0, 1, 1, 1};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i, 0, h) cin >> s[i];
  dsu uf(h * w);
  rep(i, 0, h) rep(j, 0, w)
  {
    if (s[i][j] == '.')
      continue;
    rep(n, 0, 8)
    {
      int i2 = i + di[n], j2 = j + dj[n];
      if (i2 < 0 or i2 >= h or j2 < 0 or j2 >= w)
        continue;
      if (s[i2][j2] == '#')
        uf.merge(i * w + j, i2 * w + j2);
    }
  }
  set<int> ans;
  rep(i, 0, h) rep(j, 0, w) if (s[i][j] == '#') ans.insert(uf.leader(i * w + j));
  cout << ans.size() << endl;
}