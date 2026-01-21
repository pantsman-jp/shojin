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
  vector<vector<pair<int, ll>>> g(n);
  rep(_, 0, m)
  {
    int u, v;
    ll w;
    cin >> u >> v >> w;
    u--, v--;
    g[u].push_back({v, w}), g[v].push_back({u, -w});
  }
  vector<ll> ans(n);
  vector<bool> seen(n);
  queue<int> q;
  rep(i, 0, n)
  {
    if (seen[i])
      continue;
    seen[i] = true;
    q.push(i);
    while (!q.empty())
    {
      int u = q.front();
      q.pop();
      for (auto [v, w] : g[u])
      {
        if (seen[v])
          continue;
        seen[v] = true;
        ans[v] = ans[u] + w;
        q.push(v);
      }
    }
  }
  for (auto x : ans)
    cout << x << " ";
  cout << endl;
}