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

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  rep(_, 0, m)
  {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].push_back(b);
  }
  queue<int> q;
  q.push(0);
  vector<int> dist(n, inf);
  dist[0] = 0;
  while (!q.empty())
  {
    int u = q.front();
    q.pop();
    for (int v : g[u])
    {
      if (v == 0)
      {
        cout << dist[u] + 1 << endl;
        return 0;
      }
      if (dist[v] == inf)
      {
        dist[v] = dist[u] + 1;
        q.push(v);
      }
    }
  }
  cout << -1 << endl;
}