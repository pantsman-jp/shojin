#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
using ll = long long;
const ll inf = 1LL << 60;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<int> b(n), w(m);
  rep(i, 0, n) cin >> b[i];
  rep(i, 0, m) cin >> w[i];
  sort(b.rbegin(), b.rend()), sort(w.rbegin(), w.rend());
  vector<ll> s(n + 1, 0), t(m + 1, 0), maxt(m + 1, 0);
  rep(i, 0, n) s[i + 1] = s[i] + b[i];
  rep(i, 0, m) t[i + 1] = t[i] + w[i], maxt[i + 1] = max(maxt[i], t[i + 1]);
  ll ans = 0;
  rep(i, 0, n + 1) ans = max(ans, s[i] + maxt[min(i, m)]);
  cout << ans << endl;
}