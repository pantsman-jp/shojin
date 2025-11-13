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
  ld t, a;
  cin >> n >> t >> a;
  vector<ld> h(n);
  rep(i, 0, n) cin >> h[i];
  int ans = 0;
  ld best = inf;
  rep(i, 0, n)
  {
    ld diff = abs(t - h[i] * 0.006 - a);
    if (diff < best)
      best = diff, ans = i + 1;
  }
  cout << ans << endl;
}