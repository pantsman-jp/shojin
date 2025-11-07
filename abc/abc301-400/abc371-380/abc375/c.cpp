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
  int n;
  cin >> n;
  vector<string> a(n), b(n, string(" ", n));
  rep(i, 0, n) cin >> a[i];
  rep(i, 0, n) rep(j, 0, n)
  {
    int d = min({i + 1, j + 1, n - i, n - j}), ni = i, nj = j;
    rep(_, 0, d % 4)
    {
      int ti = nj, tj = n - 1 - ni;
      ni = ti, nj = tj;
    }
    b[ni][nj] = a[i][j];
  }
  rep(i, 0, n)
  {
    rep(j, 0, n) cout << b[i][j];
    cout << endl;
  }
}