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
  int n, m;
  ll k;
  cin >> n >> m >> k;
  vector<ll> a(n), b(m), suma(n + 1), sumb(m + 1);
  rep(i, 0, n) cin >> a[i], suma[i + 1] = suma[i] + a[i];
  rep(i, 0, m) cin >> b[i], sumb[i + 1] = sumb[i] + b[i];
  int ans = 0;
  rep(i, 0, n + 1)
  {
    if (suma[i] > k)
      break;
    int j = upper_bound(all(sumb), k - suma[i]) - sumb.begin() - 1;
    ans = max(ans, i + j);
  }
  cout << ans << endl;
}