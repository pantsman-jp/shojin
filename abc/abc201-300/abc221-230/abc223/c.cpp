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
  vector<double> a(n), b(n);
  double t = 0;
  rep(i, 0, n) cin >> a[i] >> b[i], t += a[i] / b[i];
  t /= 2;
  double ans = 0;
  rep(i, 0, n)
  {
    double nt = a[i] / b[i];
    if (nt > t)
    {
      ans += b[i] * t;
      break;
    }
    ans += a[i], t -= nt;
  }
  cout << fixed << setprecision(10) << ans << endl;
}