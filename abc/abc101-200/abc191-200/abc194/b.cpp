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
  vector<ll> a(n), b(n);
  rep(i, 0, n) cin >> a[i] >> b[i];
  ll ans = inf;
  rep(i, 0, n) rep(j, 0, n)
  {
    if (i == j)
      ans = min(ans, a[i] + b[i]);
    else
      ans = min(ans, max(a[i], b[j]));
  }
  cout << ans << endl;
}