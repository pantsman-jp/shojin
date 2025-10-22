#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
using namespace std;
using ll = long long;

ll n;
double a[509], b[509], c[509];

bool check(double x, double y)
{
  for (ll i = 1; i < n + 1; i++)
  {
    if (a[i] * x + b[i] * y > c[i])
      return false;
  }
  return true;
}

int main()
{
  cin >> n;
  for (ll i = 1; i < n + 1; i++)
    cin >> a[i] >> b[i] >> c[i];
  double ans = 0.0;
  for (ll i = 1; i < n + 1; i++)
  {
    for (ll j = i + 1; j < n + 1; j++)
    {
      if (a[i] * b[j] == a[j] * b[i])
        continue;
      double px = (c[i] * b[j] - c[j] * b[i]) / (a[i] * b[j] - a[j] * b[i]);
      double py = (c[i] * a[j] - c[j] * a[i]) / (b[i] * a[j] - b[j] * a[i]);
      if (check(px - 0.00000001, py - 0.00000001))
        ans = max(ans, px + py);
    }
  }
  cout << fixed << setprecision(10) << ans << endl;
}