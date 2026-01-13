#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rrep(i, a, b) for (int i = (a) - 1; i >= b; i--)
#define all(p) p.begin(), p.end()
#define rall(p) p.rbegin(), p.rend()
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define yn(p) cout << (p ? "Yes\n" : "No\n");
#define dout(f) cout << fixed << setprecision(10) << f << '\n';
using ll = long long;
using ld = long double;
using P = pair<int, int>;
const int inf = 1 << 30;
const ll INF = 1LL << 60;
// const ll mod =;

const vector<int> di = {-1, 0, 1, 0};
const vector<int> dj = {0, 1, 0, -1};

bool out(int i, int j, int h, int w)
{
  return i < 0 or h - 1 < i or j < 0 or w - 1 < j;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int h, w;
  cin >> h >> w;
  vector<string> a(h);
  rep(i, 0, h) cin >> a[i];
  vector dist(h, vector<vector<int>>(w, vector<int>(2, inf)));
  queue<tuple<int, int, int>> q;
  auto push = [&](int i, int j, int k, int d)
  {
    if (dist[i][j][k] != inf)
      return;
    dist[i][j][k] = d;
    q.emplace(i, j, k);
  };
  rep(i, 0, h) rep(j, 0, w) if (a[i][j] == 'S') push(i, j, 0, 0);
  while (!q.empty())
  {
    auto [i, j, k] = q.front();
    q.pop();
    int d = dist[i][j][k];
    if (a[i][j] == 'G')
    {
      cout << d << endl;
      return 0;
    }
    rep(v, 0, 4)
    {
      int ni = i + di[v], nj = j + dj[v];
      if (out(ni, nj, h, w) or a[ni][nj] == '#')
        continue;
      if ((k == 0 and a[ni][nj] == 'x') or (k == 1 and a[ni][nj] == 'o'))
        continue;
      int nk = k;
      if (a[ni][nj] == '?')
        nk ^= 1;
      push(ni, nj, nk, d + 1);
    }
  }
  cout << -1 << endl;
}