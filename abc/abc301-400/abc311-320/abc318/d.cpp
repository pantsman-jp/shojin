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

int n;
vector<vector<ll>> d;
vector<bool> seen;

ll dfs()
{
  int u = 0;
  while (u < n and seen[u])
    u++;
  if (u == n)
    return 0;
  seen[u] = true;
  ll ans = dfs();
  rep(v, u + 1, n)
  {
    if (seen[v])
      continue;
    seen[v] = true;
    chmax(ans, d[u][v] + dfs());
    seen[v] = false;
  }
  seen[u] = false;
  return ans;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  d.resize(n, vector<ll>(n));
  rep(i, 0, n) rep(j, i + 1, n)
  {
    cin >> d[i][j];
    d[j][i] = d[i][j];
  }
  seen.resize(n);
  cout << dfs() << endl;
}