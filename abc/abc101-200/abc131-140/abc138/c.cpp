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
  vector<ld> v(n);
  rep(i, 0, n) cin >> v[i];
  sort(all(v));
  ld ans = v[0];
  rep(i, 1, n) ans = (ans + v[i]) / 2;
  cout << fixed << setprecision(10) << ans << endl;
}