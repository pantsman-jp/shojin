#include <bits/stdc++.h>
using namespace std;
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
  vector<string> g(h), ans(h, string(w, '#'));
  rep(i, 0, h) cin >> g[i];
  rep(i, 0, h) rep(j, 0, w)
  {
    if (g[i][j] == '#')
      continue;
    int cnt = 0;
    rep(k, 0, 8)
    {
      int ni = i + di[k], nj = j + dj[k];
      if (ni < 0 or ni >= h or nj < 0 or nj >= w)
        continue;
      if (g[ni][nj] == '#')
        cnt++;
    }
    ans[i][j] = char('0' + cnt);
  }
  rep(i, 0, h) cout << ans[i] << endl;
}