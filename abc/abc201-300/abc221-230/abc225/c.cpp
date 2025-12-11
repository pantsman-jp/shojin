#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
#define yn(p) cout << (p ? "Yes" : "No") << '\n';
using ll = long long;
using P = pair<int, int>;
const ll inf = 1LL << 60;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> b(n, vector<int>(m));
  rep(i, 0, n) rep(j, 0, m) cin >> b[i][j];
  bool ok = true;
  rep(i, 0, n) rep(j, 0, m - 1)
  {
    if ((b[i][j] - 1) / 7 != (b[i][j + 1] - 1) / 7 or b[i][j] + 1 != b[i][j + 1])
      ok = false;
  }
  rep(i, 0, n - 1) rep(j, 0, m) if (b[i + 1][j] - b[i][j] != 7) ok = false;
  yn(ok);
}