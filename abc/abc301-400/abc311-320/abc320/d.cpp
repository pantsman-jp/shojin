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
using P = pair<int, int>;
const int inf = 1 << 30;
const ll INF = 1LL << 60;
const ld pi = acosl(-1.0L);
// const ll mod = 998244353;
// const ll mod = 1000000007;

vector<vector<tuple<int, ll, ll>>> g;
vector<bool> seen;
vector<pair<ll, ll>> pos;

void dfs(int u, ll x, ll y)
{
  seen[u] = true;
  pos[u] = {x, y};
  for (auto [v, dx, dy] : g[u])
    if (!seen[v])
      dfs(v, x + dx, y + dy);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  g.resize(n);
  rep(_, 0, m)
  {
    int a, b;
    ll x, y;
    cin >> a >> b >> x >> y;
    a--, b--;
    g[a].push_back({b, x, y});
    g[b].push_back({a, -x, -y});
  }
  seen.resize(n), pos.resize(n);
  dfs(0, 0, 0);
  rep(i, 0, n)
  {
    if (seen[i])
      cout << pos[i].first << " " << pos[i].second << endl;
    else
      cout << "undecidable" << endl;
  }
}