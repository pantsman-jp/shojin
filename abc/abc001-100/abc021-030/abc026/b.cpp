#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
using ld = long double;
const ll inf = 1LL << 60;
const ld pi = 3.1415926535;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<ld> r(n);
  rep(i, 0, n) cin >> r[i];
  sort(all(r), greater<ld>());
  ld ans = 0.0;
  rep(i, 0, n)
  {
    if (i % 2 == 0)
      ans += pi * r[i] * r[i];
    else
      ans -= pi * r[i] * r[i];
  }
  cout << fixed << setprecision(10) << ans << endl;
}