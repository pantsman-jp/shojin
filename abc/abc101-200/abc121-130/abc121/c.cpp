#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using ll = long long;
using P = pair<ll, ll>;
const ll inf = 1LL << 60;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  ll m;
  cin >> n >> m;
  vector<P> ab(n);
  rep(i, 0, n) cin >> ab[i].first >> ab[i].second;
  sort(all(ab));
  ll ans = 0;
  for (auto [a, b] : ab)
  {
    if (m <= b)
    {
      ans += a * m;
      break;
    }
    else
      ans += a * b, m -= b;
  }
  cout << ans << endl;
}