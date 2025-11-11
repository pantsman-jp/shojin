#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

double grad(double xi, double yi, double xj, double yj)
{
  return (yj - yi) / (xj - xi);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<double> x(n), y(n);
  rep(i, 0, n) cin >> x[i] >> y[i];
  int ans = 0;
  rep(i, 0, n) rep(j, 0, n)
  {
    if (j <= i)
      continue;
    double g = grad(x[i], y[i], x[j], y[j]);
    if (-1 <= g and g <= 1)
      ans++;
  }
  cout << ans << endl;
}