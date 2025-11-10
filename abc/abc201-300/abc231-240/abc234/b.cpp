#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

ll dist(int x1, int y1, int x2, int y2)
{
  return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> x(n), y(n);
  rep(i, 0, n) cin >> x[i] >> y[i];
  ll ans = -inf;
  rep(i, 0, n) rep(j, 0, n)
  {
    if (i == j)
      continue;
    ans = max(ans, dist(x[i], y[i], x[j], y[j]));
  }
  cout << fixed << setprecision(10) << sqrt(ans) << endl;
}