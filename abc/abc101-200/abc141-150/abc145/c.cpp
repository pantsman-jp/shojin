#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
using ld = long double;
const ll inf = 1LL << 60;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> x(n), y(n), path(n);
  rep(i, 0, n) cin >> x[i] >> y[i], path[i] = i;
  ld ans = 0;
  do
  {
    rep(i, 0, n - 1)
    {
      int from = path[i], to = path[i + 1];
      ans += sqrt((x[from] - x[to]) * (x[from] - x[to]) + (y[from] - y[to]) * (y[from] - y[to]));
    }
  } while (next_permutation(all(path)));
  rep(i, 0, n) ans /= (i + 1);
  cout << fixed << setprecision(10) << ans << endl;
}