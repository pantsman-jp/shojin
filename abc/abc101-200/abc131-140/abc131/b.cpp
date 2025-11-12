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
  ll n, l;
  cin >> n >> l;
  vector<ll> taste(n);
  rep(i, 0, n) taste[i] = l + i;
  ll sum = reduce(all(taste)), best = inf, ans = 0;
  rep(i, 0, n)
  {
    ll now = sum - taste[i];
    if (abs(sum - now) < best)
      best = abs(sum - now), ans = now;
  }
  cout << ans << endl;
}