#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define rrep(i, l, r) for (int i = (r) - 1; i >= (l); i--)
#define all(p) p.begin(), p.end()
#define rall(p) p.rbegin(), p.rend()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define yn(p) cout << (p ? "Yes\n" : "No\n");
#define dout(f) cout << fixed << setprecision(10) << f << '\n';
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using P = pair<int, int>;
const int inf = 1 << 30;
const ll INF = 1LL << 60;
const ld pi = acosl(-1.0L);
// using mint = modint998244353;
// using mint = modint1000000007;

int n1, n2, m;
vector<vector<int>> g;

int bfs(int u)
{
  vector<int> dist(n1 + n2);
  vector<bool> seen(n1 + n2);
  queue<int> q;
  q.push(u);
  dist[u] = 0;
  seen[u] = true;
  while (!q.empty())
  {
    int v = q.front();
    q.pop();
    for (int w : g[v])
    {
      if (!seen[w])
      {
        q.push(w);
        seen[w] = true;
        dist[w] = dist[v] + 1;
      }
    }
  }
  return *max_element(all(dist));
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n1 >> n2 >> m;
  g.resize(n1 + n2);
  rep(_, 0, m)
  {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].push_back(b), g[b].push_back(a);
  }
  cout << bfs(0) + bfs(n1 + n2 - 1) + 1 << endl;
}