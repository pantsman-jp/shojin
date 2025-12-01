#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

int h, w, ans;
vector<vector<int>> a;

void dfs(int i, int j, set<int> s)
{
  if (s.count(a[i][j]))
    return;
  s.insert(a[i][j]);
  if (i == h - 1 and j == w - 1)
  {
    ans++;
    return;
  }
  if (j + 1 < w)
    dfs(i, j + 1, s);
  if (i + 1 < h)
    dfs(i + 1, j, s);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> h >> w;
  a.resize(h, vector<int>(w));
  rep(i, 0, h) rep(j, 0, w) cin >> a[i][j];
  dfs(0, 0, set<int>());
  cout << ans << endl;
}