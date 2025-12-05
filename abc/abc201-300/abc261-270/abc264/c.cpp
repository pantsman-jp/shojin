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
  int h1, w1;
  cin >> h1 >> w1;
  vector a(h1, vector<int>(w1));
  rep(i, 0, h1) rep(j, 0, w1) cin >> a[i][j];
  int h2, w2;
  cin >> h2 >> w2;
  vector b(h2, vector<int>(w2));
  rep(i, 0, h2) rep(j, 0, w2) cin >> b[i][j];
  rep(hs, 0, 1 << h1) rep(ws, 0, 1 << w1)
  {
    vector<int> is, js;
    rep(i, 0, h1) if (hs >> i & 1) is.push_back(i);
    rep(j, 0, w1) if (ws >> j & 1) js.push_back(j);
    if (is.size() != h2 or js.size() != w2)
      continue;
    vector c(h2, vector<int>(w2));
    rep(i, 0, h2) rep(j, 0, w2) c[i][j] = a[is[i]][js[j]];
    if (b == c)
    {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}
