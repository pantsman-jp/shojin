#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

const vector<int> di = {-1, -1, 1, 1};
const vector<int> dj = {-1, 1, -1, 1};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i, 0, h) cin >> s[i];
  int n = min(h, w);
  vector<int> ans(n + 1);
  rep(i, 0, h) rep(j, 0, w)
  {
    if (s[i][j] != '#')
      continue;
    int cnt = 0;
    rep(v, 0, 4)
    {
      int ni = i + di[v], nj = j + dj[v];
      if (ni < 0 or nj < 0 or ni >= h or nj >= w)
        continue;
      if (s[ni][nj] == '#')
        cnt++;
    }
    if (cnt == 4)
    {
      int l = 0, ni = i, nj = j;
      while (true)
      {
        ni++, nj++;
        if (ni == h or nj == w)
          break;
        if (s[ni][nj] != '#')
          break;
        l++;
      }
      ans[l]++;
    }
  }
  rep(i, 1, n + 1) cout << ans[i] << ' ';
  cout << endl;
}