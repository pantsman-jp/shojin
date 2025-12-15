#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;
const double pi = acos(-1.0);

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  double a, b, h, m;
  cin >> a >> b >> h >> m;
  double theta = pi * (60.0 * h - 11.0 * m) / 360.0;
  cout << fixed << setprecision(10) << sqrt(a * a + b * b - 2.0 * a * b * cos(theta)) << endl;
}