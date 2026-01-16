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
// const ll mod = 998244353;
// const ll mod = 1000000007;

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
  vector<string> s(h);
  rep(i, 0, h) cin >> s[i];
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  a--, b--, c--, d--;
  vector dist(h, vector<int>(w, inf));
  vector used(h, vector<bool>(w));
  deque<P> q;
  auto push = [&](int i, int j, int d, int cost)
  {
    if (dist[i][j] <= d)
      return;
    dist[i][j] = d;
    if (cost == 0)
      q.emplace_front(i, j);
    else
      q.emplace_back(i, j);
  };
  push(a, b, 0, 0);
  while (!q.empty())
  {
    auto [i, j] = q.front();
    q.pop_front();
    if (used[i][j])
      continue;
    used[i][j] = true;
    int d = dist[i][j];
    rep(v, 0, 4)
    {
      int ni = i + di[v], nj = j + dj[v];
      if (out(ni, nj, h, w))
        continue;
      if (s[ni][nj] == '.')
        push(ni, nj, d, 0);
    }
    rep(v, 0, 4)
    {
      int ni = i, nj = j;
      rep(_, 0, 2)
      {
        ni += di[v];
        nj += dj[v];
        if (out(ni, nj, h, w))
          break;
        push(ni, nj, d + 1, 1);
      }
    }
  }
  cout << dist[c][d] << endl;
}