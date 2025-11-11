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
  int h, w;
  cin >> h >> w;
  vector<vector<ll>> a(h, vector<ll>(w));
  rep(i, 0, h) rep(j, 0, w) cin >> a[i][j];
  ll mini = inf, ans = 0;
  rep(i, 0, h) mini = min(mini, *min_element(all(a[i])));
  rep(i, 0, h) rep(j, 0, w) ans += (a[i][j] - mini);
  cout << ans << endl;
}