#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

bool solve()
{
  int n, m;
  cin >> n >> m;
  vector<int> deg(n);
  dsu uf(n);
  rep(i, 0, m)
  {
    int a, b;
    cin >> a >> b;
    a--, b--;
    deg[a]++, deg[b]++;
    uf.merge(a, b);
  }
  int one = 0;
  rep(i, 0, n)
  {
    if (deg[i] == 0 or deg[i] > 2)
      return false;
    if (deg[i] == 1)
      one++;
  }
  if (one != 2)
    return false;
  return uf.size(0) == n;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  if (solve())
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}