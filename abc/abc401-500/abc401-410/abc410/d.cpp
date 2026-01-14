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

struct Edge
{
  int to, w;
};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  int W = 1 << 10;
  vector<vector<Edge>> g(n);
  rep(i, 0, m)
  {
    int a, b, w;
    cin >> a >> b >> w;
    a--, b--;
    g[a].emplace_back(b, w);
  }
  vector<bool> visited(n * W);
  queue<int> q;
  auto push = [&](int v, int x)
  {
    int vid = v * W + x;
    if (visited[vid])
      return;
    visited[vid] = true;
    q.push(vid);
  };
  push(0, 0);
  while (!q.empty())
  {
    int vid = q.front();
    q.pop();
    int v = vid / W, x = vid % W;
    for (auto e : g[v])
      push(e.to, x ^ e.w);
  }
  rep(x, 0, W)
  {
    if (visited[(n - 1) * W + x])
    {
      cout << x << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}