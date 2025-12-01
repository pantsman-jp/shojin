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
  int ans = 0;
  rep(i, 0, m)
  {
    int a, b;
    cin >> a >> b;
    a--, b--;
    if (uf.same(a, b))
      ans++;
    uf.merge(a, b);
  }
  cout << ans << endl;
}