#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using ll = long long;
const ll inf = 1LL << 60;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  int ans = 0;
  map<pair<int, int>, int> g;
  rep(i, 0, m)
  {
    int u, v;
    cin >> u >> v;
    if (u == v)
    {
      ans++;
      continue;
    }
    if (u > v)
      swap(u, v);
    g[{u, v}]++;
  }
  for (auto [_, k] : g)
    ans += k - 1;
  cout << ans << endl;
}