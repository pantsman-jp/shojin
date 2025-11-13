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
  vector<ll> t(5);
  rep(i, 0, 5) cin >> t[i];
  ll ans = inf;
  sort(all(t));
  do
  {
    ll time = 0;
    rep(i, 0, 4) time += ((t[i] + 9) / 10) * 10;
    ans = min(ans, time + t[4]);
  } while (next_permutation(all(t)));
  cout << ans << endl;
}