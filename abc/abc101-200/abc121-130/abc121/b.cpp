#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, c;
  cin >> n >> m >> c;
  vector<int> b(m);
  vector<vector<int>> a(n, vector<int>(m));
  rep(i, 0, m) cin >> b[i];
  rep(i, 0, n) rep(j, 0, m) cin >> a[i][j];
  int ans = 0;
  rep(i, 0, n)
  {
    int pts = c;
    rep(j, 0, m) pts += a[i][j] * b[j];
    if (pts > 0)
      ans++;
  }
  cout << ans << endl;
}