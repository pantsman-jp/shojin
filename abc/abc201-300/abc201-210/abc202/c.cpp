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
  vector<int> a(n), b(n), c(n);
  rep(i, 0, n) cin >> a[i], a[i]--;
  rep(i, 0, n) cin >> b[i], b[i]--;
  rep(i, 0, n) cin >> c[i], c[i]--;
  vector<ll> cnt(n);
  rep(j, 0, n) cnt[b[c[j]]]++;
  ll ans = 0;
  rep(i, 0, n) ans += cnt[a[i]];
  cout << ans << endl;
}