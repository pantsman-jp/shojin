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
  int n, k;
  cin >> n >> k;
  vector<set<int>> g(n);
  vector<int> deg(n);
  rep(i, 0, n - 1)
  {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].insert(b), g[b].insert(a);
    deg[a]++, deg[b]++;
  }
  set<int> v;
  rep(i, 0, k)
  {
    int vi;
    cin >> vi;
    v.insert(vi - 1);
  }
  queue<int> q;
  rep(i, 0, n) if (deg[i] == 1 and v.count(i) == 0) q.push(i);
  int cnt = 0;
  while (!q.empty())
  {
    int u = q.front();
    q.pop();
    if (g[u].empty())
      continue;
    int nu = *g[u].begin();
    g[u] = {};
    cnt++;
    g[nu].erase(u);
    deg[nu]--;
    if (deg[nu] == 1 and v.count(nu) == 0)
      q.push(nu);
  }
  cout << n - cnt << endl;
}