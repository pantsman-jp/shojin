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
  int n, si = -1;
  cin >> n;
  vector<int> X(n), Y(n), H(n);
  rep(i, 0, n)
  {
    cin >> X[i] >> Y[i] >> H[i];
    if (H[i] > 0)
      si = i;
  }
  int ansx = -1, ansy = -1, ansh = -1;
  rep(x, 0, 101) rep(y, 0, 101)
  {
    int h = H[si] + abs(x - X[si]) + abs(y - Y[si]);
    bool ok = true;
    rep(i, 0, n)
    {
      if (H[i] > 0 and h - H[i] != abs(x - X[i]) + abs(y - Y[i]))
        ok = false;
      if (H[i] == 0 and h > abs(x - X[i]) + abs(y - Y[i]))
        ok = false;
    }
    if (ok)
      ansx = x, ansy = y, ansh = h;
  }
  cout << ansx << ' ' << ansy << ' ' << ansh << endl;
}