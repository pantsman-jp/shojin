#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

void solve()
{
  int n, m;
  cin >> n >> m;
  vector<int> x(n), y(m);
  rep(i, 0, n) cin >> x[i];
  rep(i, 0, m) cin >> y[i];
  vector<vector<int>> a(n, vector<int>(m));
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  rep(_, 0, t) solve();
}