#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (ll i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using ll = long long;
using P = pair<ll, ll>;
const ll inf = 1LL << 60;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n, w;
  cin >> n >> w;
  vector<P> ab(n);
  rep(i, 0, n) cin >> ab[i].first >> ab[i].second;
  sort(all(ab), greater<P>());
  ll ans = 0;
  for (auto [a, b] : ab)
    ans += a * min(w, b), w -= min(w, b);
  cout << ans << endl;
}