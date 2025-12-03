#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  dsu uf(n);
  rep(_, 0, m)
  {
    int u, v;
    cin >> u >> v;
    u--, v--;
    uf.merge(u, v);
  }
  int ans = 0;
  rep(v, 0, n) if (v == uf.leader(v)) ans++;
  cout << ans << endl;
}